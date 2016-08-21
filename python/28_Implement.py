#!/usr/bin/python
import sys
import os

class Solution(object):
    def strStr(self, haystack, needle):
    	n, m = len(haystack), len(needle)
    	if m == 0:
    		return 0
    	if n == 0:
    		return -1
    	for i in range(n - m + 1):
    		j = 0
    		while j < m:
    			if haystack[i + j] == needle[j]:
    				j += 1
    			else:
    				break
    		if j == m:
    			return i
    	return -1
        


def main():
    s = Solution()
    print s.strStr("abcdefghqwertyuiop", "defg")
    print s.strStr("a", "a")

if __name__ == "__main__":
    main()
