#!/usr/bin/python
import sys
import os


'''
[2, 3, 6, 7] and target 7, -> [ [7], [2, 2, 3] ]
'''

class Solution(object):
    def combinationSum(self, nums, target):
    	nums = sorted(nums)
    	res, part = [], []
    	return self.dfs(nums, target, part, res)

    def dfs(self, nums, target, part, res):
    	if target == 0:
    		res.append(part)
    	n = len(nums)
    	for i in range(n):
    		if nums[i] > target:
    			break
    		self.dfs(nums[i:n], target - nums[i], part + [nums[i]], res)
        return res

def main():
    s = Solution()
    nums = [2, 3, 6, 7]
    target = 7
    print s.combinationSum(nums, target)

if __name__ == "__main__":
    main()
