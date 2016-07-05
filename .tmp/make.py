import os
import sys


if len(sys.argv) != 2:
    print "You should type in the Question Number!"

input = sys.argv[1]

f = open('/home/wayne/leetCode/.tmp/question.list')

dict = {}
for l in f:
    l = l.strip().split('\t')
    
    line = l[0].split("  ")
    no = line[0]
    name = line[1]
    name_ = name.split(" ")
    new_name = "_".join(name_)
    if len(no) < 2:
        title = no + new_name
    else:
        title = no + "_" + new_name
    dict[no] = title


os.system('cp /home/wayne/leetCode/.tmp/framework.py /home/wayne/leetCode/' + dict[input] + ".py")
os.system('cp /home/wayne/leetCode/.tmp/framework.cpp /home/wayne/leetCode/' + dict[input] + ".cpp")

