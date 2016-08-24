#!/usr/bin/python
import sys
import os


class Solution(object):
    def count(self, n):
        last = '*'
        count = 0
        res = ""
        for i in str(n): # don't use enumerate to skip 1st loop, insufficient
        	if last != '*' and last != i:
        		res += str(count) + last
        		count = 0
        	count += 1
        	last = i
       	res += str(count) + last
        return res
    def countAndSay(self, n):
        s='1'
        for i in range(2,n+1):
            s=self.count(s)
        return s        


def main():
    s = Solution()
    print s.countAndSay(5)


if __name__ == "__main__":
    main()
