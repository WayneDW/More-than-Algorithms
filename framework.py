#!/usr/bin/python
import sys
import re
import os

class leetCode:
    # using __init__ for future function updates
    def __init__(self, f):
        self.f = f
    def convert(self, id): # return 001 for #1, 098 for #98
        if len(id) < 2: id = "00" + id
        elif len(id) < 3: id = "0" + id
        return id
    def title(self, num): # input question number
        fileList = open(self.f)
        num_list = {}
        for l in fileList:
            l = l.strip().split("\t")
            par = l[0].split(" ")
            id = self.convert(par[0])
            title = ""
            tag = 0
            for pars in range(1, len(par)):
                if par[pars] != "" and not re.match(r'(.*)[%\(\)](.*)', par[pars]):
                    title += "_" + par[pars]
                    #print title
                    tag = 1
                if tag == 1 and par[pars] == "":
                    break
            num_list[id] = id + title
            key = self.convert(str(num)) # change key format to satisfy dict
        return num_list[key].replace("'", '') # shell can't recognize what ' is 

# check if file exists, do nothing if it does, avoid overwrite
class framework:
    def __init__(self, name):
        self.name = name
    def cp(self):
        '''
        if not os.path.isfile("./python/" + self.name + ".py"):
            os.system('cp ./.tmp/template.py ./python/' + self.name + '.py')
            print self.name + ".py generated successfully!"
        else:
            print self.name + ".py already existed!"
        '''
        if not os.path.isfile("./c++/" + self.name + ".cpp"):
            os.system('cp ./.tmp/template.cpp ./c++/' + self.name + '.cpp')
            print self.name + ".cpp generated successfully!"
        else:
            print self.name + ".cpp already existed!"
        

def main():
    if len(sys.argv) < 2:
        print "please input the question number!"
        exit()
    # Get the name of this question
    L = leetCode("./.tmp/list")
    # input question number, return fileName
    fileName = L.title(sys.argv[1])
    print "Let's deal with " + fileName
    # Generate the framework file
    new = framework(fileName)
    new.cp()

if __name__ == "__main__":
    main()
