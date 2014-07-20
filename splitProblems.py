#!/usr/bin/python


import os
path = "./"
title = "problems"
new_path = os.path.join(path, title)
if not os.path.isdir(new_path):
    os.makedirs(new_path)

summaryFile = "summary100.md"


f = None

with open(summaryFile,"r") as fs:
	while(True):
		line = fs.readline()
		if not line:
			f.close()
			break
		if line.startswith("##") and line[2]!="#":
			if f!=None:
				f.close()
			problemName = line[2:].strip()
			print problemName
			f = open(new_path+"/"+problemName+".md","wa")
		if f:
			f.write(line)
			
		
