#!/bin/bash
wsgi_file=/home/codingevents/OPC/website/django.wsgi;
pkill -9 django
touch $wsgi_file;

