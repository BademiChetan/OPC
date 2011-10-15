# -*- coding: utf-8 -*-

#django imports
from django import forms
from django.forms import ModelForm
from django.db import models as d_models
from django.contrib.auth.models import User
from django.template import Template, Context
from django.utils.safestring import mark_safe
#project imports
from website.teams import *
from website import settings
from captcha.fields import CaptchaField
import re

username_range = re.compile(r"[a-zA-Z0-9_]+$")
names_range = re.compile(r"[a-zA-Z ]+$")
alphanumeric = re.compile(r"[a-zA-Z0-9]+$")

COUNTRY_CHOICES = (
    ("",""),
    ("Afghanistan" , "Afghanistan" ) , 
    ("Albania" , "Albania" ) , 
    ("Algeria" , "Algeria" ) , 
    ("Andorra" , "Andorra" ) , 
    ("Angola" , "Angola" ) , 
    ("Antigua & Deps" , "Antigua & Deps" ) , 
    ("Argentina" , "Argentina" ) , 
    ("Armenia" , "Armenia" ) , 
    ("Australia" , "Australia" ) , 
    ("Austria" , "Austria" ) , 
    ("Azerbaijan" , "Azerbaijan" ) , 
    ("Bahamas" , "Bahamas" ) , 
    ("Bahrain" , "Bahrain" ) , 
    ("Bangladesh" , "Bangladesh" ) , 
    ("Barbados" , "Barbados" ) , 
    ("Belarus" , "Belarus" ) , 
    ("Belgium" , "Belgium" ) , 
    ("Belize" , "Belize" ) , 
    ("Benin" , "Benin" ) , 
    ("Bhutan" , "Bhutan" ) , 
    ("Bolivia" , "Bolivia" ) , 
    ("Bosnia Herzegovina" , "Bosnia Herzegovina" ) , 
    ("Botswana" , "Botswana" ) , 
    ("Brazil" , "Brazil" ) , 
    ("Brunei" , "Brunei" ) , 
    ("Bulgaria" , "Bulgaria" ) , 
    ("Burkina" , "Burkina" ) , 
    ("Burundi" , "Burundi" ) , 
    ("Cambodia" , "Cambodia" ) , 
    ("Cameroon" , "Cameroon" ) , 
    ("Canada" , "Canada" ) , 
    ("Cape Verde" , "Cape Verde" ) , 
    ("Central African Rep" , "Central African Rep" ) , 
    ("Chad" , "Chad" ) , 
    ("Chile" , "Chile" ) , 
    ("China" , "China" ) , 
    ("Colombia" , "Colombia" ) , 
    ("Comoros" , "Comoros" ) , 
    ("Congo" , "Congo" ) , 
    ("Congo {Democratic Rep}" , "Congo {Democratic Rep}" ) , 
    ("Costa Rica" , "Costa Rica" ) , 
    ("Croatia" , "Croatia" ) , 
    ("Cuba" , "Cuba" ) , 
    ("Cyprus" , "Cyprus" ) , 
    ("Czech Republic" , "Czech Republic" ) , 
    ("Denmark" , "Denmark" ) , 
    ("Djibouti" , "Djibouti" ) , 
    ("Dominica" , "Dominica" ) , 
    ("Dominican Republic" , "Dominican Republic" ) , 
    ("East Timor" , "East Timor" ) , 
    ("Ecuador" , "Ecuador" ) , 
    ("Egypt" , "Egypt" ) , 
    ("El Salvador" , "El Salvador" ) , 
    ("Equatorial Guinea" , "Equatorial Guinea" ) , 
    ("Eritrea" , "Eritrea" ) , 
    ("Estonia" , "Estonia" ) , 
    ("Ethiopia" , "Ethiopia" ) , 
    ("Fiji" , "Fiji" ) , 
    ("Finland" , "Finland" ) , 
    ("France" , "France" ) , 
    ("Gabon" , "Gabon" ) , 
    ("Gambia" , "Gambia" ) , 
    ("Georgia" , "Georgia" ) , 
    ("Germany" , "Germany" ) , 
    ("Ghana" , "Ghana" ) , 
    ("Greece" , "Greece" ) , 
    ("Grenada" , "Grenada" ) , 
    ("Guatemala" , "Guatemala" ) , 
    ("Guinea" , "Guinea" ) , 
    ("Guinea-Bissau" , "Guinea-Bissau" ) , 
    ("Guyana" , "Guyana" ) , 
    ("Haiti" , "Haiti" ) , 
    ("Honduras" , "Honduras" ) , 
    ("Hungary" , "Hungary" ) , 
    ("Iceland" , "Iceland" ) , 
    ("India" , "India" ) , 
    ("Indonesia" , "Indonesia" ) , 
    ("Iran" , "Iran" ) , 
    ("Iraq" , "Iraq" ) , 
    ("Ireland {Republic}" , "Ireland {Republic}" ) , 
    ("Israel" , "Israel" ) , 
    ("Italy" , "Italy" ) , 
    ("Ivory Coast" , "Ivory Coast" ) , 
    ("Jamaica" , "Jamaica" ) , 
    ("Japan" , "Japan" ) , 
    ("Jordan" , "Jordan" ) , 
    ("Kazakhstan" , "Kazakhstan" ) , 
    ("Kenya" , "Kenya" ) , 
    ("Kiribati" , "Kiribati" ) , 
    ("Korea North" , "Korea North" ) , 
    ("Korea South" , "Korea South" ) , 
    ("Kosovo" , "Kosovo" ) , 
    ("Kuwait" , "Kuwait" ) , 
    ("Kyrgyzstan" , "Kyrgyzstan" ) , 
    ("Laos" , "Laos" ) , 
    ("Latvia" , "Latvia" ) , 
    ("Lebanon" , "Lebanon" ) , 
    ("Lesotho" , "Lesotho" ) , 
    ("Liberia" , "Liberia" ) , 
    ("Libya" , "Libya" ) , 
    ("Liechtenstein" , "Liechtenstein" ) , 
    ("Lithuania" , "Lithuania" ) , 
    ("Luxembourg" , "Luxembourg" ) , 
    ("Macedonia" , "Macedonia" ) , 
    ("Madagascar" , "Madagascar" ) , 
    ("Malawi" , "Malawi" ) , 
    ("Malaysia" , "Malaysia" ) , 
    ("Maldives" , "Maldives" ) , 
    ("Mali" , "Mali" ) , 
    ("Malta" , "Malta" ) , 
    ("Marshall Islands" , "Marshall Islands" ) , 
    ("Mauritania" , "Mauritania" ) , 
    ("Mauritius" , "Mauritius" ) , 
    ("Mexico" , "Mexico" ) , 
    ("Micronesia" , "Micronesia" ) , 
    ("Moldova" , "Moldova" ) , 
    ("Monaco" , "Monaco" ) , 
    ("Mongolia" , "Mongolia" ) , 
    ("Montenegro" , "Montenegro" ) , 
    ("Morocco" , "Morocco" ) , 
    ("Mozambique" , "Mozambique" ) , 
    ("Myanmar, {Burma}" , "Myanmar, {Burma}" ) , 
    ("Namibia" , "Namibia" ) , 
    ("Nauru" , "Nauru" ) , 
    ("Nepal" , "Nepal" ) , 
    ("Netherlands" , "Netherlands" ) , 
    ("New Zealand" , "New Zealand" ) , 
    ("Nicaragua" , "Nicaragua" ) , 
    ("Niger" , "Niger" ) , 
    ("Nigeria" , "Nigeria" ) , 
    ("Norway" , "Norway" ) , 
    ("Oman" , "Oman" ) , 
    ("Pakistan" , "Pakistan" ) , 
    ("Palau" , "Palau" ) , 
    ("Panama" , "Panama" ) , 
    ("Papua New Guinea" , "Papua New Guinea" ) , 
    ("Paraguay" , "Paraguay" ) , 
    ("Peru" , "Peru" ) , 
    ("Philippines" , "Philippines" ) , 
    ("Poland" , "Poland" ) , 
    ("Portugal" , "Portugal" ) , 
    ("Qatar" , "Qatar" ) , 
    ("Romania" , "Romania" ) , 
    ("Russian Federation" , "Russian Federation" ) , 
    ("Rwanda" , "Rwanda" ) , 
    ("St Kitts & Nevis" , "St Kitts & Nevis" ) , 
    ("St Lucia" , "St Lucia" ) , 
    ("Saint Vincent & the Grenadines" , "Saint Vincent & the Grenadines" ) , 
    ("Samoa" , "Samoa" ) , 
    ("San Marino" , "San Marino" ) , 
    ("Sao Tome & Principe" , "Sao Tome & Principe" ) , 
    ("Saudi Arabia" , "Saudi Arabia" ) , 
    ("Senegal" , "Senegal" ) , 
    ("Serbia" , "Serbia" ) , 
    ("Seychelles" , "Seychelles" ) , 
    ("Sierra Leone" , "Sierra Leone" ) , 
    ("Singapore" , "Singapore" ) , 
    ("Slovakia" , "Slovakia" ) , 
    ("Slovenia" , "Slovenia" ) , 
    ("Solomon Islands" , "Solomon Islands" ) , 
    ("Somalia" , "Somalia" ) , 
    ("South Africa" , "South Africa" ) , 
    ("Spain" , "Spain" ) , 
    ("Sri Lanka" , "Sri Lanka" ) , 
    ("Sudan" , "Sudan" ) , 
    ("Suriname" , "Suriname" ) , 
    ("Swaziland" , "Swaziland" ) , 
    ("Sweden" , "Sweden" ) , 
    ("Switzerland" , "Switzerland" ) , 
    ("Syria" , "Syria" ) , 
    ("Taiwan" , "Taiwan" ) , 
    ("Tajikistan" , "Tajikistan" ) , 
    ("Tanzania" , "Tanzania" ) , 
    ("Thailand" , "Thailand" ) , 
    ("Togo" , "Togo" ) , 
    ("Tonga" , "Tonga" ) , 
    ("Trinidad & Tobago" , "Trinidad & Tobago" ) , 
    ("Tunisia" , "Tunisia" ) , 
    ("Turkey" , "Turkey" ) , 
    ("Turkmenistan" , "Turkmenistan" ) , 
    ("Tuvalu" , "Tuvalu" ) , 
    ("Uganda" , "Uganda" ) , 
    ("Ukraine" , "Ukraine" ) , 
    ("United Arab Emirates" , "United Arab Emirates" ) , 
    ("United Kingdom" , "United Kingdom" ) , 
    ("United States" , "United States" ) , 
    ("Uruguay" , "Uruguay" ) , 
    ("Uzbekistan" , "Uzbekistan" ) , 
    ("Vanuatu" , "Vanuatu" ) , 
    ("Vatican City" , "Vatican City" ) , 
    ("Venezuela" , "Venezuela" ) , 
    ("Vietnam" , "Vietnam" ) , 
    ("Yemen" , "Yemen" ) , 
    ("Zambia" , "Zambia" ) , 
    ("Zimbabwe" , "Zimbabwe" ) , 
)

def get_language_choices():
    query = models.Language.objects.all()
    ret = []
    for row in query:
        temp = []
        temp.append( row ) 
        temp.append( row ) 
        ret.append( temp ) 
    ans = tuple(ret)
    #print ans
    return ans
    


def get_problem_choices():
    query = models.Problem.objects.all()
    ret = []
    print len(query)
    for row in query:
        temp = []
        temp.append( row.name ) 
        temp.append( row.name ) 
        ret.append( temp ) 
    ans = tuple(ret)
    #print ans
    return ans
        
class LoginForm(forms.Form):
    username=forms.CharField(help_text='Your team name.')
    password=forms.CharField(widget=forms.PasswordInput, help_text='Your password')
    
class SubmissionForm(forms.Form):
    lang            = forms.CharField   (max_length = 50, required = False, widget=forms.Select(choices=get_language_choices()) )
    problem         = forms.CharField   (max_length = 50, required = False, widget=forms.Select(choices=get_problem_choices()) )
    program         = forms.FileField   ()      
    
    
class TeamRegistrationForm(ModelForm):
    username        = forms.CharField   (max_length=50, help_text='Username for you to login. Only letters, numbers and underscores are allowed.')
    password        = forms.CharField   (min_length=6, max_length=50, widget=forms.PasswordInput, help_text='Enter a password that you can remember.')
    password_again  = forms.CharField   (min_length=6, max_length=50, widget=forms.PasswordInput, help_text='Enter the same password that you entered above.')
    display_name    = forms.CharField   (max_length = 50, required = True, help_text='Team name -- as it is to be displayed.')
    organisation    = forms.CharField   (max_length = 50, required = False, help_text='School, University or Organisation you want to represent.')
    name1           = forms.CharField   (max_length = 50, required = True, help_text='Name of the first team member.')
    name2           = forms.CharField   (max_length = 50, required = False, help_text='Name of the second team member (optional).')
    name3           = forms.CharField   (max_length = 50, required = False, help_text='Name of the third team member (optional).')
    email           = forms.EmailField   (max_length = 50, required = True, help_text='Email of one of the team members.')
    country         = forms.CharField   (max_length = 50, required = False, widget=forms.Select(choices=COUNTRY_CHOICES) )
    captcha         = CaptchaField()
    
    class Meta:
        model = models.TeamProfile
        fields=('username','password','password_again','display_name','organisation','name1','name2','name3','email', 'country',)
    
    def clean_username(self):
        if not username_range.search(self.cleaned_data['username']):
           raise forms.ValidationError(u'Usernames can only contain letters, numbers and underscores')
        if User.objects.filter(username=self.cleaned_data['username']):
            pass
        else:
            return self.cleaned_data['username']
        raise forms.ValidationError('This username is already taken! Please choose another one.')
        
    def clean_password(self):
        if self.prefix:
            field_name1 = '%s-password'%self.prefix
            field_name2 = '%s-password_again'%self.prefix
        else:
            field_name1 = 'password'
            field_name2 = 'password_again'
            
        if self.data[field_name1] != '' and self.data[field_name1] != self.data[field_name2]:
            raise forms.ValidationError ("The entered passwords do not match.")
        else:
            return self.data[field_name1]
    
    def clean_name1(self):
        if not names_range.search(self.cleaned_data['name1']):
            raise forms.ValidationError(u'Names can contain only letters and spaces.')
        return self.cleaned_data['name1']
    
    def clean_name2(self):
        if self.cleaned_data['name2'] == "":
            return self.cleaned_data['name2']
        if not names_range.search(self.cleaned_data['name2']):
            raise forms.ValidationError(u'Names can contain only letters and spaces.')
        return self.cleaned_data['name2']
    
    def clean_name3(self):
        if self.cleaned_data['name3'] == "":
            return self.cleaned_data['name3']
        if not names_range.search(self.cleaned_data['name3']):
            raise forms.ValidationError(u'Names can contain only letters and spaces.')
        return self.cleaned_data['name3']
    
    def clean_email(self):
        if models.User.objects.filter(email=self.cleaned_data['email']):
            pass
        else:
            return self.cleaned_data['email']
        raise forms.ValidationError('This email address has already been registered!')

class UpdateForm(forms.Form):
    display_name    = forms.CharField   (max_length = 50, required = True, help_text='Team name -- as it is to be displayed.')
    organisation    = forms.CharField   (max_length = 50, required = False, help_text='School, University or Organisation you want to represent.')
    name1           = forms.CharField   (max_length = 50, required = True, help_text='Name of the first team member.')
    name2           = forms.CharField   (max_length = 50, required = False, help_text='Name of the second team member (optional).')
    name3           = forms.CharField   (max_length = 50, required = False, help_text='Name of the third team member (optional).')
    country         = forms.CharField   (max_length = 50, required = False, widget=forms.Select(choices=COUNTRY_CHOICES) )
    
    def clean_name1(self):
        if not names_range.search(self.cleaned_data['name1']):
            raise forms.ValidationError(u'Names can contain only letters and spaces.')
        return self.cleaned_data['name1']
    
    def clean_name2(self):
        if self.cleaned_data['name2'] == "":
            return self.cleaned_data['name2']
        if not names_range.search(self.cleaned_data['name2']):
            raise forms.ValidationError(u'Names can contain only letters and spaces.')
        return self.cleaned_data['name2']
    
    def clean_name3(self):
        if self.cleaned_data['name3'] == "":
            return self.cleaned_data['name3']
        if not names_range.search(self.cleaned_data['name3']):
            raise forms.ValidationError(u'Names can contain only letters and spaces.')
        return self.cleaned_data['name3']
    
