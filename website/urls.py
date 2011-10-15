from django.conf.urls.defaults import patterns, include, url
from website import settings
# Uncomment the next two lines to enable the admin:
from django.contrib import admin
admin.autodiscover()

urlpatterns = patterns('',
    # Examples:
    # url(r'^$', 'website.views.home', name='home'),
    # url(r'^website/', include('website.foo.urls')),

    # Uncomment the admin/doc line below to enable admin documentation:
    # url(r'^admin/doc/', include('django.contrib.admindocs.urls')),
    # Uncomment the next line to enable the admin:
    url(r'^admin/', include(admin.site.urls)),
    url(r'^', include ('website.teams.urls')), 
    url(r'^captcha/', include ('website.captcha.urls')),     
)

urlpatterns += patterns('django.views.generic.simple',
    url(r'^$', 'redirect_to', {'url':'home/'}),
)
if settings.DEBUG:
    urlpatterns += patterns(
        'django.views.static',
        (r'^static_media/(?P<path>.*)$',
        'serve',
        {'document_root': '/path/to/static_media',
        'show_indexes': True }),
    )
