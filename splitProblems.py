#!/usr/bin/python

summaryFile = "summary100.md"

with open(summaryFile,"r") as f:
	while(True):
		line = f.readline()
		if not line:
			file.close()
			break
		if line.startswith("##") and line[2]!="#":
			file.close()
			problemName = line[2:]
			file = open(problemName+".md","wa")
		print file
		file.write("df")
			
		
