#!/usr/bin/python
import sys
import os

class Solution:
	def maxArea(self, height):
		'''
		height: List[int]
		rtype: int
		'''
		out = 0
		left = 0
		
		right = len(height) - 1
		while left < right:
			water = min(height[left], height[right]) * (right - left)
			print left, right, water
			if out < water:
				out = water
			if height[left] > height[right]:
				right -= 1
			else:
				left += 1
		
		return out




def main():
    s = Solution()
    print s.maxArea([1,2,4,3])

if __name__ == "__main__":
    main()
