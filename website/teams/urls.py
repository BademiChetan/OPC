# -*- coding: utf-8 -*-
from django.conf.urls.defaults import *
from django.contrib import admin
admin.autodiscover()

handler404 = "main_test.misc.util.not_found"
handler500 = "main_test.misc.util.server_error"

urlpatterns = patterns('',          
      (r'^register/$', 'website.teams.views.register'),
      (r'^home/$', 'website.teams.views.home'),
      (r'^teams/$', 'website.teams.views.teams'),
      (r'^login/$', 'website.teams.views.login'),
      (r'^logout/$', 'website.teams.views.logout'),
      (r'^problems/$', 'website.teams.views.problems'),
      (r'^update/$', 'website.teams.views.update_profile'),
      (r'^submit/$', 'website.teams.views.submit'),
      (r'^queue/(?P<pageNumber>.*)/', 'website.teams.views.queue'),
      (r'^compileoutput/(?P<submissionId>.*)/', 'website.teams.views.compileoutput'),
      (r'^ranklist/$', 'website.teams.views.ranklist'),
      (r'^ranklist/$', 'website.teams.views.ranklist'),
      (r'^team_info/(?P<team_name>.*)/$', 'website.teams.views.show_details'),
      (r'^problems/(\d{1,3})/$', 'website.teams.views.show_problems'),			# assuming no of problems will be between 1 and 999
      (r'^contact/$', 'website.teams.views.contact'),
      (r'^rules/$', 'website.teams.views.rules'),
      (r'^faq/$', 'website.teams.views.faq'),
      (r'^limit/$', 'website.teams.views.limit'),
      (r'^registered/$', 'website.teams.views.registered'),
)   



