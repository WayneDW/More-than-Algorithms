#!/usr/bin/python
import sys
import os

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stk = []
        for i in range(len(s)):
        	if s[i] == '(' or s[i] == '[' or s[i] == '{':
        		stk.append(s[i])
        	else:
        		if stk == [] or self.unmatch(stk.pop(), s[i]):
        			return False
        return stk == []

    def unmatch(self, a, b):
    	if a == '(':
    		return b != ')'
    	elif a == '[':
    		return b != ']'
    	elif a == '{':
    		return b != '}'
    	else:
    		return False



def main():
    s = Solution()
    print s.isValid("[")

if __name__ == "__main__":
    main()
