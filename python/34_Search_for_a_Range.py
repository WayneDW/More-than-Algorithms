#!/usr/bin/python
import sys
import os

'''
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
'''

class Solution(object):
    def searchRange(self, nums, target):
        n = len(nums)
        loc = self.binSearch(nums, target, 0)
        i, j, begin, end = loc, loc, loc, loc
        while i >= 0 and nums[i] == target:
        	begin = i
        	i -= 1
        while j < n and nums[j] == target:
        	end = j
        	j += 1
        return [begin, end]


    # search the minimum location of the array
    def binSearch(self, nums, target, loc):
    	n = len(nums)
    	if n == 1 and nums[0] == target:
    		return loc
    	elif n == 1 and nums[0] != target:
    		return -1
    	mid = n / 2
    	if nums[mid] <= target:
    		loc = self.binSearch(nums[mid:n], target, loc + mid)
    	else:
    		loc = self.binSearch(nums[0: mid], target, loc)
    	return loc



def main():
    s = Solution()

    nums = [5, 7, 7, 8, 8, 10]
    target = 8
    nums = [1]
    target = 0
    #print s.binSearch(nums, target, 0)
    print s.searchRange(nums, target)

if __name__ == "__main__":
    main()
