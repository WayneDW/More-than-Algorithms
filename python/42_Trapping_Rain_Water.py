#!/usr/bin/python
import sys
import os

class Solution(object):
    def trap(self, height):
    	n, vol = len(height), 0
    	leftMax, rightMax = [0] * n, [0] * n
    	for i in range(1, n):
    		leftMax[i] = max(leftMax[i - 1], height[i - 1])

    	for i in range(n - 2, 0, -1):
    		rightMax[i] = max(rightMax[i + 1], height[i + 1])
    		boundary = min(leftMax[i], rightMax[i])
    		if boundary > height[i]:
    			vol += boundary - height[i]
        return vol
        


def main():
    s = Solution()
    print s.trap([0,1,0,2,1,0,1,3,2,1,2,1])

if __name__ == "__main__":
    main()
