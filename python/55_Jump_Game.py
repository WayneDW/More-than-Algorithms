#!/usr/bin/python
import sys
import os

class Solution(object):
    def canJump(self, A):
        n = len(A)
        if n <= 1:
        	return True
        maxIdx = 0
        for i in range(n - 1):
	        maxIdx = max(maxIdx, i + A[i])
	        if maxIdx < i + 1:
	        	break
        	if maxIdx >= n - 1:
        		return True
        return False



def main():
    s = Solution()
    #print s.canJump([2,3,1,1,4])
    #print s.canJump([3,2,1,0,4])
    print s.canJump([0, 2, 3])

if __name__ == "__main__":
    main()
