#!/bin/env python
# -*- encoding: utf-8 -*-
from __future__ import print_function, unicode_literals
import json
import requests
KEYWORDS_URL = 'http://api.bosonnlp.com/keywords/analysis'
SUMMARY_URL = 'http://api.bosonnlp.com/summary/analysis'
CLASSIFY_URL = 'http://api.bosonnlp.com/classify/analysis'
import urllib
import os
import sys

reload(sys)
sys.setdefaultencoding( "utf-8" )

f = file("./datas","w")

text = sys.argv[1]
params = {'top_k': 3}
data1 = json.dumps(text)
headers1 = {'X-Token': 'TsjL7xQk.4726.T9ImfphHUZKm'}
resp = requests.post(KEYWORDS_URL, headers=headers1, params=params, data=data1.encode('utf-8'))
for word in resp.json():
	f.write(word[1])
	f.write("\n")
#文章的类型分类（新闻）
s = []
s.append(text)
data3 = json.dumps(s)
headers3 = {'X-Token': 'TsjL7xQk.4726.T9ImfphHUZKm'}
resp = requests.post(CLASSIFY_URL, headers=headers3, data=data3.encode('utf-8'))
f.write(resp.text)
f.write("\n")
# 提取文章关键词
headers2 = {'X-Token': 'TsjL7xQk.4726.T9ImfphHUZKm'}
source2 = {
'not_exceed': 0,
'percentage': 0.2,
'title': ''}
source2['content'] = text;
resp = requests.post(
SUMMARY_URL,
headers=headers2,
data=json.dumps(source2).encode('utf-8'))
f.write(json.loads(resp.text))

f.close 
