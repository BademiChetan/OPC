# Helper functions
from django.contrib import auth
from django.shortcuts import render_to_response
from django.http import HttpResponse, HttpResponseRedirect
from django.template.loader import get_template
from django.template.context import Context, RequestContext
from website import settings
import MySQLdb, re, md5, time


# Error pages
def not_found (request):
    return render_to_response('404.html', locals(), context_instance= global_context(request)) 
def server_error (request):
    return render_to_response('500.html', locals(), context_instance= global_context(request)) 
def render_home(request):
    return render_to_response('index.html', locals(), context_instance= global_context(request)) 


## Decorators ##

# Force authentication first
def needs_authentication (func):
    def wrapper (*__args, **__kwargs):
        request = __args[0]
        if not request.user.is_authenticated():
            # Return here after logging in
            request.session['from_url'] = request.path
            return HttpResponseRedirect ("%slogin/"%settings.SITE_URL)
        else:
            return func (*__args, **__kwargs)
    return wrapper

# Check for admin status. Use *after* needs_authentication. Always
def admin_only (func):
    def wrapper (*__args, **__kwargs):
        request = __args[0]
        if request.user.is_superuser:
            return func (*__args, **__kwargs)
        else:
            request.session['access_denied'] = True
            return HttpResponseRedirect ("%s/home/"%settings.SITE_URL)
    return wrapper

# For urls that can't be accessed once logged in.
def no_login (func):
    def wrapper (*__args, **__kwargs):
        request = __args[0]
        if request.user.is_authenticated():
            request.session['already_logged'] = True
            return HttpResponseRedirect ("%s/home/" %settings.SITE_URL)
        else:
            return func (*__args, **__kwargs)
    return wrapper

def global_context(request):
    context =  RequestContext (request,
            {'user':request.user,
            'SITE_URL':settings.SITE_URL,
            'MEDIA_URL':settings.MEDIA_URL,
            'SITE_URL':settings.SITE_URL,
            'SUPERUSER':request.user.is_superuser,
            'VISIBLE':settings.VISIBLE,
            })
    return context
