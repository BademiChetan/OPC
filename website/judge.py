#!/usr/bin/python2.6 
import os, sys, time, re, commands,datetime
import MySQLdb as mysql
from time import strftime
from settings import *
db = {}

TIME_IDLE_WAIT = 1 
PENALTY_TIME_IN_MINS = 20 
db['host'] = 'localhost'			    # FIXME ? 
db['user'] = DATABASES['default']['USER']
db['passwd'] = DATABASES['default']['PASSWORD']
db['db'] = DATABASES['default']['NAME']

#danger = [ 'system', 'fork', 'exec', 'cd', 'rm', 'creat', 'ps', 'Runtime', 'Process' ]  # [a-z]word[ (] is better?
danger = []


#Parsing time. Figure out how it works. Too lazy to comment. 
def get_time(s):
    days = s.split(' ')[0].split('-')[2]
    (hours,mins,seconds)=s.split(' ')[1].split(':')
    return int(days) * 24 * 3600 + int(hours) * 3600 + int(mins) * 60 + int(seconds)

def get_submission_time(t):
    print get_time(t) - get_time(START_TIME)
    return get_time(t) - get_time(START_TIME)  

try:
	conn = mysql.connect(db['host'],db['user'],db['passwd'],db['db'])
	print ">>> Connection to database started!"
except mysql.Error, e:
	print "Error %d: %s" % (e.args[0], e.args[1])
	sys.exit(1)


def run_query(q):
    curs = conn.cursor()
    curs.execute(q)
    res = curs.fetchall()
    curs.close()
    return res

def run_submission(res):
    print res
    SubmissionID = res[0]
    TeamId = res[1]
    Language = res[2]
    ProblemId = res[3]
    Timestamp = res[5];
    print Timestamp
    FileName = res[6].split('/')[1]

    MainFolder = MEDIA_ROOT.split("media")[0]
    backUpPath = MainFolder + "backup/" + FileName
    newPath = MainFolder + "submissions/" + FileName
    JailLocation = "/home/hangman/Jail/"
    backupOutput = commands.getoutput("cp %s%s %s" % (MEDIA_ROOT,res[6] , backUpPath))
    jailCopyOutput =  commands.getoutput("cp %s%s %s" % (MEDIA_ROOT,res[6] , JailLocation+FileName))
    
    print jailCopyOutput
    moveOutput =  commands.getoutput("cp %s%s %s" % (MEDIA_ROOT,res[6] , newPath))
   
    #FIXME: If you are adding more languages, change this code.
    os.chdir("%s" % JailLocation)                       #cd is not like other bash commands.
    execName = ""
    FileNameCleaned = ""
    sandbox = "zsimple"
    compileOutput = ''

    for x in danger:
        out = commands.getoutput('cat %s | grep %s' % (FileName, x))
        if(out):
            print "Danger! Danger! Red team assemble! This is not a drill!"
            print out
            q = "UPDATE teams_submission SET status = 'Compile Error' WHERE id = %d" % (SubmissionID)
            print "CE"
            run_query(q)        
            WARNING = "Your program contains the keyword %s that may compromise the security of our system. Hope you are not trying to hack." % (x) 
            q = "UPDATE teams_submission SET output = '%s' WHERE id = %d" % (WARNING, SubmissionID)
            run_query(q) 
            return 


    print "Judging: " + str(TeamId) + " " + str(SubmissionID) + " " + str(FileName) + " " + str(ProblemId) 
#   Already AC => Pack evalutation. We have less time already. 
    q = "SELECT accepted FROM teams_helper WHERE team_id = %d AND problem_id = %d "%  (TeamId,ProblemId)
    already_submitted = run_query(q)[0][0]
    if( already_submitted ):
        q = "UPDATE teams_submission SET status = 'Already Accepted' WHERE id = %d" % (sid) 
        run_query(q)
        print "AAC!"
        return 
 

    if( Language == "C++" ):
        #FIXME: File name should not have .cpp.
        execName = FileName.split('.cpp')[0]
        FileNameCleaned = execName
        compileCommand = "g++ -O2 %s -lm -o %s" % (FileName,execName) 
        compileOutput =  commands.getoutput(compileCommand)
    elif( Language == "C" ):
        #FIXME: File name should not have .cpp.
        execName = FileName.split('.c')[0]
        FileNameCleaned = execName
        compileCommand = "gcc -O2 %s -lm -o %s" % (FileName,execName) 
        compileOutput =  commands.getoutput(compileCommand)
    elif( Language == "Java" ):
        #FIXME: File name should not have .cpp.
        execName = "/usr/bin/java Main"
        FileNameCleaned = FileName.split('.java')[0]
        sandbox = "zsimple-java"
        compileCommand = "javac %s" % (FileName) 
        compileOutput =  commands.getoutput(compileCommand)
    
    re.sub("," , "\'", compileOutput)                           # Don't mess up SQL
    re.sub('"' , '\"', compileOutput)
    #FIXME: Don't give compile error when it gives a warning. 
    #FIXME: MLE
    if ( compileOutput == '' ):
        q = "SELECT points,memory_limit,time_limit FROM teams_problem WHERE id = %d" % ProblemId
        (points, memory_limit, time_limit) = run_query(q)[0]
        if(Language == "Java"):                                         # Check it out ?? 
            memory_limit += 250
            time_limit *= 1.5
        runCommand = "sudo -u hangman ../%s -t %d -m %d %s <../input/%d.in >../otherOutput/%s.out" % (sandbox, time_limit,memory_limit,execName,ProblemId, FileNameCleaned) 
        print "About to exec"
        runOutput =  commands.getoutput( runCommand )
        print runCommand
        print runOutput
        status = runOutput.split('return=')[1]
        if( status == "ok" ):
            diffStatement = "diff --ignore-all-space --ignore-blank-lines ../otherOutput/%s.out ../output/%d.out" % ( FileNameCleaned , ProblemId )
            diffOutput  = commands.getoutput(diffStatement)
            accepted = False
            if( diffOutput == ''):
                accepted = True
                q = "UPDATE teams_submission SET status = 'Accepted' WHERE id = %d" % (SubmissionID)
                run_query(q)    
                print "AC!"
                q = "UPDATE teams_problem SET ac = ac + 1 WHERE id = %d" %(ProblemId)
                run_query(q)
                q = "UPDATE teams_helper SET accepted = 1 WHERE team_id = %d AND problem_id = %d" %(TeamId,ProblemId)
                run_query(q)
                q = "SELECT incorrect from teams_helper WHERE team_id = %d AND problem_id = %d" %(TeamId,ProblemId)
                extra_penalty = run_query(q)[0][0] * PENALTY_TIME_IN_MINS * 60
                extra_penalty += get_submission_time(str(Timestamp))
                q = "UPDATE teams_rankings SET points=points+%d,penalty=penalty + %d WHERE team_id = %d"  %(points,extra_penalty,TeamId)
                run_query(q)
            else:
                print "WA"
                q = "UPDATE teams_submission SET status = 'Wrong Answer' WHERE id = %d" % (SubmissionID)
                run_query(q)                    
                q = "UPDATE teams_helper SET incorrect = incorrect + 1 WHERE team_id = %d AND problem_id = %d " % (TeamId,ProblemId)
                run_query(q)
                q = "UPDATE teams_problem SET wa = wa + 1 WHERE id = %d" %(ProblemId)
                run_query(q)
        else:
            statusMessage = ""
            if( status == "tle" ):
                statusMessage = "Time Limit Exceeded"
                q = "UPDATE teams_problem SET tle = tle + 1 WHERE id = %d" %(ProblemId)
                run_query(q)
                print "TLE"
            else:
                statusMessage = "Run Time Error"
                q = "UPDATE teams_problem SET re = re + 1 WHERE id = %d" %(ProblemId)
                run_query(q)
                print "RE"
            q = "UPDATE teams_submission SET status = '%s' WHERE id = %d" % (statusMessage,SubmissionID)
            run_query(q)                    
            q = "UPDATE teams_helper SET incorrect = incorrect + 1 WHERE team_id = %d AND problem_id = %d " % (TeamId,ProblemId)
            run_query(q)
    else:
        q = "UPDATE teams_submission SET status = 'Compile Error' WHERE id = %d" % (SubmissionID)
        print "CE"
        run_query(q)        
        q = 'UPDATE teams_submission SET output = "%s" WHERE id = %d' % (compileOutput, SubmissionID)  
        run_query(q) 
        return 
    os.chdir(MainFolder)
    

def cleanup():
    q = "UPDATE teams_submission SET status = 'Queued' WHERE status = 'Running'"    
    run_query(q)

try:
    while True:
        q = "SELECT * FROM teams_submission WHERE status = 'Queued' LIMIT 0,1" # automatically ordered by timestamp
        res = run_query(q)
        empty = ()
        if res == empty:
            time.sleep(TIME_IDLE_WAIT)
            continue
        else:
            sid = res[0][0]
            q = "UPDATE teams_submission SET status = 'Running' WHERE id = %d" % (sid) 
            run_query(q)
            run_submission(res[0])
except KeyboardInterrupt:
	cleanup()
