#!/usr/bin/python
import sys
import os

'''
For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
'''

class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        # sacrifice space to exchange for efficiency
        nums.sort()
        res, length, valuePair = [], len(nums), {}
        if length < 4:
        	return null

        for i in range(length - 1):
        	for j in range(i + 1, length):
        		valuePair.setdefault(nums[i] + nums[j], []).append((i, j))
        
        for i in range(length - 2):
        	for j in range(i + 1, length):
        		T = target - nums[i] - nums[j]
        		if T in valuePair:
        			index = valuePair[T]
        			for k in index:
        				if k[0] > j:
        					res.append((nums[i], nums[j], nums[k[0]], nums[k[1]]))
        return list(set(res))




def main():
    s = Solution()
    print s.fourSum([1, 0, -1, 0, -2, 2], 0)

if __name__ == "__main__":
    main()
