#!/usr/bin/python
import sys
import os

class Solution(object):
    def removeDuplicates(self, nums):
        n = len(nums)
        if n <= 1:
        	return nums
        i, j = 0, 1
        while i < n - j:
        	if nums[i] == nums[i + 1]:
        		nums.remove(nums[i])
        		j += 1
        	else:
        		i += 1
        return nums



def main():
    s = Solution()
    print s.removeDuplicates([0, 1, 1, 2, 2, 2, 3])

if __name__ == "__main__":
    main()
