#!/usr/bin/python
#coding=utf-8

import os
import sys

files = os.listdir(".")

L = ["字符串和数组","栈","链表","二叉树","图","递归","动归"]
info = "\n".join(["%d.%s" %(i,L[i]) for i in range(len(L))])

line = []
with open("#log.md","r") as f:
    lines = f.readlines()

for fName in files:
    with open(fName,"r") as cur:
        curLines = cur.readlines()
        abstract = "".join(curLines[:5])
    cata = raw_input("\n-----------------\n%s\n\n%s\n\n%s\n\n ***input a catagory*** : " %(fName,info,abstract) )
    try:
        cata_id = int(cata)
        cata = L[cata_id]
    except:
        L.append(cata)
        info = "\n".join(["%d.%s" %(i,L[i]) for i in range(len(L))])
    item = "%s\t%s" %(cata,fName)


    with open("#log.md","a") as f:
        f.write(item+"\n")


