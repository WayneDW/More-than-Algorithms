#!/usr/bin/python
import sys
import os

class Solution(object):
    def searchInsert(self, nums, target):
    	n = len(nums)
    	loc = self.binSearch(nums, target, 0)
    	#print "?" , loc
    	if nums[loc] == target:
    		return loc
    	elif nums[loc] < target:
    		return loc + 1
    	return 0
    # search the minimum location of the array
    def binSearch(self, nums, target, loc):
    	n = len(nums)
    	if n == 1:
    		return loc
    	mid = n / 2
    	if nums[mid] <= target:
    		loc = self.binSearch(nums[mid: n], target, loc + mid)
    	else:
    		loc = self.binSearch(nums[0: mid], target, loc)
    	return loc  


def main():
    s = Solution()
    nums = [5, 7, 8, 10]
    target = 9
    nums = [1]
    target = 0 
    print s.binSearch(nums, target, 0)
    print s.searchInsert(nums, target)

if __name__ == "__main__":
    main()
