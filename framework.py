#!/usr/bin/python
import sys
import re
import os

class leetCode:
    def __init__(self, f):
        self.f = f
    def list(self):
        fileList = open(self.f)
        num_list = {}
        for l in fileList:
            l = l.strip().split("\t")
            par = l[0].split(" ")
            id = par[0]
            title = ""
            tag = 0
            for pars in range(1, len(par)):
                if par[pars] != "" and not re.match(r'(.*)[%\(\)](.*)', par[pars]):
                    title += "_" + par[pars]
                    tag = 1
                if tag == 1 and par[pars] == "":
                    break
            num_list[id] = id + title
        return num_list
    def title(self, num):
        # input the question number
        # output the framework file name
        return self.list()[num]

class framework:
    def __init__(self, name):
        self.name = name
    def cp(self):
        if not os.path.isfile("./python/" + self.name + ".py"):
            os.system('cp ./.tmp/framework.py ./python/' + self.name + '.py')
            print self.name + ".py generated successfully!"
        else:
            print self.name + ".py already existed!"

        if not os.path.isfile("./c++/" + self.name + ".cpp"):
            os.system('cp ./.tmp/framework.cpp ./c++/' + self.name + '.cpp')
            print self.name + ".cpp generated successfully!"
        else:
            print self.name + ".cpp already existed!"
        

def main():
    if len(sys.argv) < 2:
        print "please input the question number!"
        exit()
    # Get the name of this question
    L = leetCode("./.tmp/list")
    fileName = L.title(sys.argv[1])
    print "Let's deal with " + fileName
    # Generate the framework file
    new = framework(fileName)
    new.cp()


if __name__ == "__main__":
    main()
