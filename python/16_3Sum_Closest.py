#!/usr/bin/python
import sys
import os
import math

'''
    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
'''

class Solution:
	def threeSumClosest(self, nums, target):
		nums.sort()
		out = 0
		MIN = 10 ** 10
		for i in range(len(nums) - 2):
			left = i + 1
			right = len(nums) - 1
			while left < right:
				total = nums[i] + nums[left] + nums[right]
				if total == target:
					return target
				elif total < target:
					left += 1
				else:
					right -= 1
				diff = abs(total - target)
				if diff < MIN:
					MIN = diff
					out = total
		return out

def main():
    s = Solution()
    print s.threeSumClosest([-1, 2, 1, -4], 1)

if __name__ == "__main__":
    main()
