#!/usr/bin/python

class Solution(object):
    def simplifyPath(self, path):
    	path += "/"
    	res, part = "", ""
    	vec = []
    	for i in range(len(path)):
    		if path[i] != '/':
    			part += path[i]
    		else:
    			if part == "":
    				continue
    			elif part == "..":
    				if vec == []:
    					part = ""
    					continue
    				vec.pop()
    			elif part != ".":
    				vec.append(part)
    			part = ""
    	for i in range(len(vec)):
    		res += "/" + vec[i]
    	if vec == []:
    		res = "/"
    	return res



def main():
    s = Solution()
    print s.simplifyPath("/...")

if __name__ == "__main__":
    main()
