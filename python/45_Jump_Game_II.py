#!/usr/bin/python
import sys
import os

class Solution(object):
    def jump(self, nums):
        n, k = len(nums), 0
        jMax = 0; i = 0; lastMax = 0; tag = 0
        while jMax < n - 1:
        	#print i, jMax
        	while i <= lastMax:
        		jMax = max(jMax, i + nums[i])
        		if jMax < i + 1:  # it can't reach the next point, stop
        			tag = 1
        			break
        		i += 1
        	k += 1
        	lastMax = jMax
        	if tag:
        		break
        return k


def main():
	s = Solution()
	print s.jump([7,0,9,6,9,6,1,7,9,0,1,2,9,0,3])
	print s.jump([2, 1])
	print s.jump([0])

if __name__ == "__main__":
    main()
