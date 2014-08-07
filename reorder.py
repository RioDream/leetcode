import os

name2file = {}
files = os.listdir("./problems")
for f in files:
    name = f.split(".")[1]
    print name
    name2file[name] = f


def formatNum3(num):
    if num<10:
        return "00%d" %num
    elif num<100:
        return "0%d" %num
    else:
        return "%d" %num


count = 1
with open("tmp","r") as f:
    while True:
        line = f.readline()
        if not line:break

        items = line.split("201")
        name = items[0].strip()
        ori_name = name2file[name]
        new_name = "%s.%s.md" %(formatNum3(count),name)
        cmd = "cp \"./problems/%s\" \"./newP/%s\""  %(ori_name,new_name)
        print cmd
        os.system(cmd)
        count+=1
