from django.shortcuts import render_to_response
from django.http import HttpResponse, HttpResponseRedirect
from django.core.exceptions import ObjectDoesNotExist
from django.contrib import auth
from django.contrib.auth.models import User, Group
from django.template.loader import get_template
from django.template.context import Context, RequestContext
from django.utils.translation import ugettext as _
from django.core.mail import send_mail,EmailMessage,SMTPConnection
from django.contrib.sessions.models import Session
from django.utils import simplejson
from django.http import Http404
from django.contrib.auth import authenticate
from django import forms
import models,forms
import random, datetime, os
from website import settings
from website.settings import *
from website.teams.models import *
from website.util import *
import sha


def login (request):
    form=forms.LoginForm()
    if 'logged_in' in request.session and request.session['logged_in'] == True:
        return HttpResponseRedirect("%shome" % settings.SITE_URL)
    if request.method == 'POST':
        data = request.POST.copy()
        form = forms.LoginForm(data)
        if form.is_valid():
            user = authenticate(username=form.cleaned_data['username'], password=form.cleaned_data["password"])
            if user is not None and user.is_active == True:
                auth.login (request, user)
                request.session['logged_in'] = True
                request.session['UserID'] = user.id
                return HttpResponseRedirect ("%shome/" % settings.SITE_URL)
            else:
                request.session['invalid_login'] = True
                request.session['logged_in'] = False
                errors=[]
                errors.append("Incorrect username and password combination!")
                return render_to_response('login.html', locals(), context_instance=global_context(request))

        else:   
            #invalid_login = session_get(request, "invalid_login")
            form = forms.LoginForm () 
    return render_to_response('login.html', locals(), context_instance=global_context(request))
    
def logout(request):
    if request.user.is_authenticated():
        auth.logout (request)
        return render_to_response('logout.html', locals(), context_instance=global_context(request))        
    return HttpResponseRedirect('%slogin/'%settings.SITE_URL)        
    
def home(request):
    return render_to_response('home.html', locals(), context_instance=global_context(request))
    
def register(request):
    if request.method=='POST':
        data = request.POST.copy()
        form = forms.TeamRegistrationForm(data)
        if form.is_valid():
            new_user = User.objects.create_user(username = form.cleaned_data['username'], password = form.cleaned_data['password'], email = form.cleaned_data['email'])
            new_user.is_active = True
            new_user.save()
            teamprofile = TeamProfile(
                user = new_user,
                display_name    = form.cleaned_data['display_name'],
                organisation    = form.cleaned_data['organisation'],
                name1           = form.cleaned_data['name1'],
                name2           = form.cleaned_data['name2'],
                name3           = form.cleaned_data['name3'],
                country         = form.cleaned_data['country'],
            )
            f = open('/home/codingevents/OPC/website/registration_log', 'a')
            s = form.cleaned_data['username'] + '|' + form.cleaned_data['email'] + '|' + form.cleaned_data['display_name'] + '|' + \
                form.cleaned_data['organisation'] + '|' + form.cleaned_data['name1'] + '|' + form.cleaned_data['name2'] + '|' + form.cleaned_data['name3'] + \
                form.cleaned_data['country'] + '\n'
            f.write(s)
            f.close()
            teamprofile.save()
            return HttpResponseRedirect('%sregistered/'%settings.SITE_URL)        
    else:
        form = forms.TeamRegistrationForm()
    return render_to_response('register.html', locals(),context_instance=global_context(request))
    
def teams(request):
    teams = TeamProfile.objects.all()
    return render_to_response('teams.html', locals(), context_instance=global_context(request) )

def show_details(request, team_name):
    user_id = User.objects.filter(username = team_name)
    team = TeamProfile.objects.filter(user = user_id)[0]
    return render_to_response('team_info.html', locals(), context_instance=global_context(request) )

def problems(request):
    problems = Problem.objects.all().order_by('id')
    return render_to_response('problems.html', locals(), context_instance=global_context(request))

def show_problems(request, number):
    problem = Problem.objects.get(id = number)
    return render_to_response('show_problems.html', locals(), context_instance=global_context(request))

def update_profile(request):
    if not request.user.is_authenticated():
        return HttpResponseRedirect('%slogin/'%settings.SITE_URL)        
    if request.method=='POST':
        data = request.POST.copy()
        form = forms.UpdateForm(data)
        if form.is_valid():
            teamprofile = TeamProfile.objects.get( user = request.user )
            teamprofile.display_name    = form.cleaned_data['display_name']
            teamprofile.organisation    = form.cleaned_data['organisation']
            teamprofile.name1           = form.cleaned_data['name1']
            teamprofile.name2           = form.cleaned_data['name2']
            teamprofile.name3           = form.cleaned_data['name3']
            teamprofile.country         = form.cleaned_data['country'] 
            teamprofile.save()
        return HttpResponseRedirect('%steams/'%settings.SITE_URL)        
    else:
        form = forms.UpdateForm()
    return render_to_response('update.html', locals(),context_instance=global_context(request))



#TODO: Impose file size limit!
def submit(request):
    if not request.user.is_authenticated():
        return HttpResponseRedirect('%slogin/'%settings.SITE_URL)        

    userid = auth.get_user(request)
    if request.method=='POST':
        form = forms.SubmissionForm(request.POST,request.FILES)
        request.FILES['program'].name = sha.new(str(random.random()) + "WE CAN HAZ THE SECURITY :D").hexdigest() + request.FILES['program'].name
        if form.is_valid():
            newSubmission = Submission(
            team = TeamProfile.objects.get(user=userid), #request.session['UserID']),
            language = Language.objects.get(name=form.cleaned_data['lang']),
            problem = Problem.objects.get(name=form.cleaned_data['problem']),
            timestamp = datetime.datetime.now(),
            status = "Queued",
            output = "Submitted",
            program = request.FILES['program']
            ) 
            team = TeamProfile.objects.get(user=userid)
            problem = Problem.objects.get(name=form.cleaned_data['problem'])
            allSubmissions = Submission.objects.filter( team = team , problem = problem ) 

            if( allSubmissions.count() >= 50 ):
                return HttpResponseRedirect("%slimit/" % settings.SITE_URL)

            try:
                res = Helper.objects.get(team = team, problem = problem)
            except:
                newHelper = Helper(team = team,problem = problem,incorrect = 0,accepted=False)
                newHelper.save()
            try:
                newRanking = Rankings.objects.get( team = team ) 
            except:
                newRanking = Rankings(team = team, points = 0 , penalty = 0 )
                newRanking.save()
            newSubmission.save()
            return HttpResponseRedirect("%squeue/1/"%settings.SITE_URL)
    else:
        form = forms.SubmissionForm()
    return render_to_response('submit.html', locals(), context_instance=global_context(request))

def queue(request,pageNumber):
    pageNumber = int(pageNumber)
    stop = min( pageNumber * 25 , Submission.objects.count())
    start = max( 0 , stop - 25 ) 
    subs = Submission.objects.all().order_by('-id')[start:stop]
    totalPages = (Submission.objects.count() + 24 ) / 25 
    pages = [] 
    for i in range(totalPages):
        pages.append(i+1)
    Prev = pageNumber - 1
    Next = pageNumber + 1 
    return render_to_response('queue.html', locals(), context_instance=global_context(request))

def contact(request):
    return render_to_response('contact.html', locals(), context_instance=global_context(request))

def faq(request):
    return render_to_response('faq.html', locals(), context_instance=global_context(request))

def rules(request):
    return render_to_response('rules.html', locals(), context_instance=global_context(request))

def registered(request):
    return render_to_response('registered.html', locals(), context_instance=global_context(request))

def ranklist(request):
    rankings = Rankings.objects.all().order_by('-points','penalty')
    for row in rankings:
        row.team_id = TeamProfile.objects.get(id = row.team_id).display_name
    return render_to_response('ranklist.html', locals(), context_instance=global_context(request))

def compileoutput(request,submissionId):
    sub = Submission.objects.get( id = submissionId )
    if( sub.team.user != request.user and request.user.is_superuser == False ):
        raise Http404
    output = sub.output
    return render_to_response('compileoutput.html',locals(),context_instance = global_context(request))

def limit(request):
    return render_to_response('limit.html', locals(), context_instance=global_context(request))
