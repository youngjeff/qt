#!/bin/env python
import types  
import urllib2  
import json  
import os
import sys
#-*-coding:utf-8 -*-
url0 = "http://api.map.baidu.com/telematics/v3/weather?location="
url1 = "&output=json&ak=ozO9AVLiHTGEltbNzUxVKPCk"
url2 = sys.argv[1]
def registerUrl():  
    try:  
        url =url0 +  url2 + url1
        data = urllib2.urlopen(url).read()  
	print data
        return data  
	print (url)
	#return url
    except Exception,e:  
        print e


f = open('./weathers','w') 
f.write(registerUrl())
f.close


