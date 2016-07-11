#!/usr/bin/python
import sys
import os

class Solution(object):
    def longestCommonPrefix(self, strs):
    	lcp = ""
    	if len(strs) < 1:
    		return lcp
    	for i in range(len(strs[0])):
    		for j in range(1, len(strs)):
    			if i >= len(strs[j]) or strs[0][i] != strs[j][i]:
    				return lcp
    		lcp += strs[0][i]
    	return lcp


def main():
    s = Solution()
    strs = ["abc", "abd"]
    print s.longestCommonPrefix(strs)

if __name__ == "__main__":
    main()
