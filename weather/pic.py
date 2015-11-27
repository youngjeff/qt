#!/bin/env python
import urllib
import os
import sys

url1 = sys.argv[1]
url2 = sys.argv[2]
#url = "http://api.map.baidu.com/images/weather/day/zhongyu.png"
url = url1
path = url2
data = urllib.urlopen(url).read() 
f = file(path,"wb")
f.write(data)
f.close 
