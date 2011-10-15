from django.db import models
from django.contrib.auth.models import User
# Create your models here.

class TeamProfile(models.Model):
    user            = models.ForeignKey     (User, unique = True)
    display_name    = models.CharField      (max_length = 50, blank = False, null = True) 
    organisation    = models.CharField      (max_length = 50, blank = False, null = False ) 
    name1           = models.CharField      (max_length = 50, blank = False, null = False )
    name2           = models.CharField      (max_length = 50, blank = True, null = True )
    name3           = models.CharField      (max_length = 50, blank = True, null = True )
    country         = models.CharField      (max_length = 50, blank = True, null = False, default = "Citizen of the World")
    
    def __unicode__(self):
        return self.user.username
        
    class Admin:
        list_display   = ('display_name', 'organisation', 'country')
    
    class Meta:
        ordering = ['display_name', 'country', 'organisation', 'name1', 'name2', 'name3']

class Problem(models.Model):
    name              = models.CharField       (max_length = 200)
    description       = models.CharField       (max_length = 10000)
    input_format      = models.CharField       (max_length = 10000)
    output_format     = models.CharField       (max_length = 10000)
    constraints       = models.CharField       (max_length = 10000)
    time_limit        = models.IntegerField()
    memory_limit      = models.IntegerField()
    points            = models.IntegerField()
    sample_input      = models.CharField       (max_length = 10000)
    sample_output     = models.CharField       (max_length = 10000)
    ac                = models.IntegerField    (default = 0)
    wa                = models.IntegerField    (default = 0)
    tle               = models.IntegerField   (default = 0)
    re                = models.IntegerField    (default = 0)
	
    def __str__(self):
	return self.name
	
    class Admin:
	pass

class Language(models.Model):
	name = models.CharField (max_length = 20, primary_key = True)

	def __str__(self):
		return self.name
	
	class Admin:
		pass

class Submission(models.Model):
	team            = models.ForeignKey   (TeamProfile)
	language        = models.ForeignKey       (Language)
	problem         = models.ForeignKey       (Problem)
	status          = models.CharField 	  (max_length = 50) 
	timestamp       = models.DateTimeField( null = True)
	program         = models.FileField(upload_to="submissions/")
	output          = models.CharField(max_length=10000,null = True)

class Helper(models.Model):
	team        = models.ForeignKey (TeamProfile)
	problem 	= models.ForeignKey (Problem)
	incorrect 	= models.IntegerField()
	accepted    = models.BooleanField()             
	
	def __str__(self):
		return self.problem.name + " --> " + self.team.user.username
	
	class Admin:
		pass

class Rankings(models.Model):
	team 		= models.ForeignKey (TeamProfile)
	points		= models.IntegerField()
	penalty 	= models.IntegerField()


