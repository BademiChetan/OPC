#!/usr/bin/python2.6 
import os, sys, time, re, commands 
import MySQLdb as mysql
from settings import *
db = {}

TIME_IDLE_WAIT = 1 

db['host'] = 'localhost'                # FIXME ? 
db['user'] = DATABASES['default']['USER']
db['passwd'] = DATABASES['default']['PASSWORD']
db['db'] = DATABASES['default']['NAME']

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


q = "UPDATE teams_submission SET status = 'Queued'"
run_query(q)

q = "UPDATE teams_helper SET accepted = 0, incorrect = 0 "
run_query(q)

q = "UPDATE teams_rankings SET points = 0, penalty = 0"
run_query(q)

q = "UPDATE teams_problem SET ac = 0, re = 0 , wa = 0, tle = 0"
run_query(q)
