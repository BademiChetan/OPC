#!/usr/bin/python 

import MySQLdb as mysql
import sys
import atexit

# This file contains all necessary db functions
# to be used in the judge
# -- Vimal

db = {}

db['host'] = "localhost"
db['user'] = "root"
db['passwd'] = "cleopatra"
db['db'] = "opc"

MAX_TRIES = 2

try:
  conn = mysql.connect(db['host'],db['user'],db['passwd'],db['db'])
  print ">>> Connection to database started!"
except mysql.Error, e:
  print "Error %d: %s" % (e.args[0], e.args[1])
  sys.exit(1)

# Preferred: Returns a cursor for the connection, that uses a dictionary
def cursor():
  return conn.cursor(mysql.cursors.DictCursor)

# Returns a cursor that uses indices
def _cursor():
  return conn.cursor()

# Important functions
# We do not do filtering here, assume that its all been done

# Returns the query resource after querying
def query(q):
  curs = cursor()
  i = 0
  while i < MAX_TRIES:
    i += 1
    try:
      curs.execute(q)
      break
    except:#_mysql_exceptions.OperationalError:
      continue

  return curs

def first(q):
  curs = query(q)
  ret = curs.fetchone()
  curs.close()
  return ret

def get_team_name(uid):
  q = "SELECT name FROM users WHERE uid=%d" %(uid)
  return first(q)['name']

def get_team_id(name):
  q = "SELECT uid FROM users WHERE name='%s'" %(name)
  return first(q)['uid']

def get_problem_name(pid):
  q = "SELECT pname FROM problems WHERE pid=%d" %(pid)
  return first(q)['pname']

def get_problem_id(name):
  q = "SELECT pid FROM problems WHERE pname='%s'" %(name)
  return first(q)['pid']

def get_problem_code(pid):
  q = "SELECT pcode FROM problems WHERE pid=%d" %(pid)
  return first(q)['pcode']

# Get last 10 submissions
# Returns the last 10 submissions that have not been evaluated
def get_last_n(n):
  q = "SELECT * FROM status WHERE status='Q' LIMIT 0,%d" % (n)
  print ">>> Query: %s" %(q)

  # Now the status for the above problems must be set as Running
  result = query(q).fetchall()

  for row in result:
    sid = row['sid']
    q = "UPDATE status SET status='R' WHERE sid=%d" %(sid)
    query(q).close()
  
  return result

def get_limits():
  #Returns 2-tuple (index=pid:value=memlimit,
  #      index=pid:value=timelimit)
  q = "SELECT * FROM problems"
  result = query(q).fetchall()
  
  mem_limit = {}
  time_limit = {}
  for row in result:
    pid = '%s' % (row['pid'])
    mem = int(row['mlimit'])
    time = int(row['tlimit'])
    mem_limit[pid] = mem
    time_limit[pid] = time
  
  return (mem_limit, time_limit)
    

def reset_submissions():
  # Resets all submissions
  q = "UPDATE status SET error = NULL, status='Q', exetime='-'"
  query(q).close()
  q = "TRUNCATE TABLE solved"
  query(q).close()

  return True

# Sets the status for a particular submission ID
def set_status(id, status, score='-', error = ""):
  id = int(id)
  error = mysql.escape_string(error)

  q = "UPDATE status SET status='%s', error='%s', score='%s'\
       WHERE sid='%s'" % (status, error, score, id)

  query(q).close()

  return True

def revert_last_submit(sid):
  sid = int(sid)
  q = "SELECT * FROM status WHERE sid=%d" %(sid)
  res = query(q)
  row = res.fetchone()
  res.close()

  uid = row['uid']
  pid = row['pid']

  # revert the submission
  q = "UPDATE lastsubmit SET last=NULL, count=count-1 WHERE \
       uid=%d AND pid=%d" %(uid, pid)

  query(q).close()
  
def update_time(sid, time):
  q = "UPDATE status SET exetime='%s' WHERE sid=%s" %(time, sid)
  query(q).close()


def update_score(pid, sid, score):
  sid = int(sid)
  q = "SELECT * FROM status WHERE sid=%d" % (sid)
  res = query(q)
  row = res.fetchone()
  uid = row['uid']
  res.close()
  
  # Get the last submission of this problem, if its there
  q = "SELECT * FROM solved WHERE uid='%s' AND \
       pid='%s'" %(uid, pid)

  res = query(q); row = res.fetchone(); res.close()
  
  # If its not there, then this is the first one
  if row == None:
    q = "INSERT INTO solved (uid, sid, pid, score) \
         VALUES ('%s', '%s', '%s', '%s')" \
         % (uid, sid, pid, score)
    query(q).close()
  else:
    ########################################
    #  Assumption -- Score is maximized    #
    ########################################
    prevscore = float(row['score'])
    # Assume that we have to maximize score
    # update new score if its greater
    if prevscore < float(score):
      q = "UPDATE solved SET \
           score='%s', sid='%s' WHERE \
           uid='%s' AND pid='%s'" % (score, sid, uid, pid)
      query(q).close()

  return True


def get_problem_points(pid):
  q = "SELECT points FROM problems WHERE pid='%s'" % (pid)
  return int(query(q).fetchone()['points'])

def clear_running():
  q = "UPDATE status SET status='Q' WHERE status='R'"
  query(q).close()
  return True


""" Clean up functions should go in here """
def cleanup():
  conn.close()
  sys.exit(0)

# Clean up on exit
atexit.register(cleanup)

