from django.contrib import admin
from website.teams.models import TeamProfile, Problem, Language, Submission

class TeamProfileAdmin(admin.ModelAdmin):
    fields = ['display_name', 'country', 'organisation', 'name1', 'name2', 'name3']

admin.site.register(TeamProfile, TeamProfileAdmin)
admin.site.register(Problem)
admin.site.register(Language)
admin.site.register(Submission)
