#!/usr/bin/python


import os
path = "./"
title = "problems"
new_path = os.path.join(path, title)
if not os.path.isdir(new_path):
    os.makedirs(new_path)

summaryFile = "summary100.md"


def toStr(num):
	numStr = str(num)
	if num<100:
		numStr = "0"+numStr
	if num<10:
		numStr = "0"+numStr
	return numStr

f = None

num = 1

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
			numStr = toStr(num)
			print numStr + "."+ problemName
			f = open(new_path+"/"+numStr+"."+problemName+".md","wa")
			num += 1
		if f:
			f.write(line)
			
		
