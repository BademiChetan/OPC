#!/usr/bin/python2.2

import os, sys, time, string
import db
import atexit

# Languages our judge (should) support
LANG_C = 'c'
LANG_CPP = 'c++'
LANG_JAVA = 'java'
LANG_PERL = 'perl'
LANG_PYTHON = 'python'
MB = 1024*1024L
MAX_STDOUT_SIZE = 8 * MB
SANDBOX = './zsimple'
WRAPPER = 'su -l jail -c '
BASE = '/var/opc'

# seconds to wait if there is no submission to be evaluated
TIME_IDLE_WAIT = 2 

# Extensions
extensions = {  LANG_CPP:'cpp',
                LANG_C:'c', 
                LANG_PYTHON:'py', 
                LANG_PERL:'pl'
             }
             
needCompile = [ LANG_CPP, LANG_C, LANG_JAVA ]

# Interpreters for the interpreted languages
interpreter = { LANG_PYTHON: '/usr/bin/python', 
                LANG_PERL:'/usr/bin/perl'
              }
              
(memLimit, timeLimit) = db.get_limits();

contest = "opc"
#contest = "apc"

log = open('log.txt', 'a')

def U(user, p, status):
  log.write("%s: %s\t%d\t%s\n" % (time.ctime(), user, p, status))
  log.flush()


def Execute(cmd):
  s = os.popen(cmd)
  return (s.read(MAX_STDOUT_SIZE), s.close())

def Execute3(cmd):
  s = os.popen3(cmd)
  stdout = s[1].read(MAX_STDOUT_SIZE)
  stderr = s[2].read(MAX_STDERR_SIZE)
  s[1].close()
  s[2].close()
  return (stdout, stderr)


def CompileCommand(source, exe, log, lang):
  if lang == LANG_C:
    cmd = "gcc -Wall -O2 -lm %s -o %s" % (source, exe)
  elif lang == LANG_CPP:
    cmd = "g++ -Wall -O2 -lm %s -o %s" % (source, exe)
  elif lang == LANG_JAVA:
    cmd = "java %s %s" % (source, exe)
  else:
    cmd = "0"
  #Pipe stdout, stderr to log file
  cmd = "%s >%s 2>&1" % (cmd, log)
  return cmd
def ExecuteCommand(exe, inp, out, err, lang, problem):
  if lang == LANG_C or lang == LANG_CPP:
    cmd = "%s <%s >%s 2>%s" % (exe, inp, out, err)
  elif lang == LANG_PYTHON or lang == LANG_PERL or lang == LANG_JAVA:
    cmd = "%s %s <%s >%s 2>%s" % (interpreter[lang], exe,
                                  inp, out, err)
  else:
    cmd = "0"
  problem = str(problem)
  cmd = "%s '%s -t %d -m %d %s'" \
        % (WRAPPER, SANDBOX, timeLimit[problem],\
           memLimit[problem],\
           cmd)

  return cmd


def ParseZSimpleOutput(file):
  #parse zsimple output
  status = {'return':'', 'error':'', 'time':''}

  if not os.path.exists(file):
    #internal error, put blame on user :P
    status['return'] = 'Error during execution'
    U(user, int(problem), "XE ")

    # Added by Vimal
    # Update DB
    # TODO: Where is the submission id here?
    # ANS: It will return to RunSubmission(), 
    # there, we can get things done :)
    return status

  f = open(file, 'r')
  lines = f.readlines()
  for line in lines:
    l = line.split('=', 1)
    if len(l) == 2 and l[0] in status:
      status[l[0]] = string.strip(l[1])
  return status


def RunSubmission(id):
  # Base info from DB
  # Already filled in the main loop -- Vimal
  lang = langs[id].lower()
  ext = extensions[lang].lower()
  problem = probNames[id]
  user = users[id]

  sourceFile = "%s/submissions/%s/%s/%s.%s" % (BASE, user, id, problem, ext)

  # Compile
  exeFile = "%s/submissions/%s/%s/%s.exe" % (BASE, user, id, problem)
  if lang in needCompile:
    compileLog = "%s/submissions/%s/%s/%s.compile" % (BASE, user, id, problem)
    compileCmd = CompileCommand(sourceFile, exeFile, compileLog, lang)
    
    (out, ret) = Execute(compileCmd)
    compileSuccess = False

    if ret == None:
      compileSuccess = True
    if not compileSuccess:
      print "Error compiling %s" % id
      U(user, int(problem), "CE ")
      compileOutput = ""
      if os.path.exists(compileLog):
        c = open(compileLog, 'r')
        compileOutput = c.read()
      #update in db
      
      # Added by Vimal
      # Update in db that the submisssion compilation failed
      
      db.set_status(id, 'CE', '-', compileOutput)
      return

  #Execute with stdin
  testInput = "%s/problems/%s/INP" % (BASE, problem)
  Output = "%s/submissions/%s/%s/%s.out" % (BASE, user, id, problem)
  Error = "%s/submissions/%s/%s/%s.err" % (BASE, user, id, problem)
  exeCmd = ExecuteCommand(exeFile, testInput, Output, Error, lang, problem)
  (out, ret) = Execute(exeCmd)
  executionSuccess = False
  status = ParseZSimpleOutput(Error)
  # print id, status
  if ret != None:
    print "Error executing %s" % id
    if status['return'] == "tle":
      U(user,int(problem),"TLE")
    else:
      U(user,int(problem),"XE")
    #update db about error

    # Updating, -- Vimal
    stat = ''
    if status['return'] == 'tle':
      stat = 'TLE'
    else:
      stat = 'XE'

    # Dont set any error/score information 
    db.set_status(id, stat)

    return

  if "return" in status:
    if status['return'] == 'ok':
      # update db about time
      executionSuccess = True
      # Update DB -- Vimal
      time = status['time']
      db.update_time(id, time)

    else:
      # update in db about error
      U(user,int(problem),"XE ")
      print status['return']
  else:
    # internal error, put blame on user
    # update db about error
    U(user,int(problem),"IE ")
    print "Internal error %s" % id

    # Update DB -- Vimal
    db.set_status(id, 'IE')
    #db.revert_last_submit(id)

    return

  if not executionSuccess:
    print "Error executing %s" % id
    U(user,int(problem),"XE ")
    #update db about error
    # Update DB -- Vimal
    db.set_status(id, 'XE')
    return

  # Check out with answer
  correctOutput = "%s/problems/%s/OUT" % (BASE, problem)

  if problem !=7:
        checkCmd = "diff -w -bB %s %s 1>/dev/null 2>&1" % (Output, correctOutput)
        (out, ret) = Execute(checkCmd)
        if ret == None:
          # accepted
          # update db
          print "Accepted %s" % id
          # Update DB -- Vimal
          # AC
          points = db.get_problem_points(problem)
          db.set_status(id, 'AC', points)
          db.update_score(problem, id, points)
          # update the score, in the logs
          U(user,int(problem),"AC ")
        else:
          # wrong answer
          # update db
          print "Wrong answer %s" % id
          # Update DB -- Vimal
          # WA
          db.set_status(id, 'WA')
          U(user,int(problem),"WA ")
                                                                                                    
  else:
    ########################################
    #  This section is for the NP-Complete contest #
    #  WE NEED TO GET THIS DONE :)         #
    ########################################  
    # Do we need the correct output for this problem? -- No!
    checkCmd = "%s/problems/%s/checker %s %s"\
                % (BASE, problem, correctOutput, Output)
    (out, ret) = Execute(checkCmd)
    if ret == None:
      out = string.strip(out)
      # out is score
      # update db
      # update-score iff the previous score < current-score
      # but increase the number of submissions anyway
      if out == "WA":
        # Put Wrong Answer
        print "Wrong answer %s" % id
        # Update DB -- Vimal
        # WA
        db.set_status(id, 'WA')
        U(user,int(problem),"WA ")
                                                
      else:
        points = db.get_problem_points(problem)
        db.set_status(id, 'AC', points)
        db.update_score(problem, id, points)
        # update the score, in the logs
        U(user,int(problem),"AC ")
        
    else:
      #internal error
      #update db
      print "Internal Error %s" % id
      U(user,int(problem),"IE ")
      
      # Update DB -- Vimal
      db.set_status(id, 'IE')
      #db.revert_last_submit(id)
     

def cleanup():
  print ">>> Changing status of running submissions"
  db.clear_running()
  sys.exit(0)
  
# atexit.register(cleanup)

i = 0
# Main loop
try:
  while True:
    #if not i < len(lines):
    #  break
    # get sid of problems not evaluated
    subs = db.get_last_n(10)
    
    if subs == None:
      # sleep for 2 seconds
      time.sleep(TIME_IDLE_WAIT)
      continue

    ids = []
    # get properties of sid
    langs = {}
    probNames = {}
    users = {}

    j = 0
    for row in subs:
      sid = row['sid']
      ids.append(sid)
      langs[sid] = row['lang']

      probNames[sid] = row['pid']
      #users[sid] = db.get_team_name(row['uid'])
      # Not using username anymore, using uid now.
      users[sid] = row['uid']
      
      j += 1
      i += 1
    
    # Start the judge process
    pids = []
    for id in ids:
      try:
        pid = os.fork()
      except:
        print "Fork failed."

      if pid == 0:
        RunSubmission(id)
        sys.exit(0)
      else:
        pids.append(pid)

    # wait for evaluation to finish
    for pid in pids:
      os.wait()
    time.sleep(1)
