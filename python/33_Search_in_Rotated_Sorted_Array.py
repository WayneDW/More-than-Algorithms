#!/usr/bin/python
import sys
import os


class Solution:
	def search(self, nums, target):
		minimum = self.findMin(nums, 0, nums[0])
		nums = nums[minimum:] + nums[:minimum]
		loc = self.binSearch(nums, target, 0)
		if loc == -1:
			return loc
		if loc < len(nums) - minimum:
			return minimum + loc
		else:
			return loc - len(nums) + minimum

	def findMin(self, nums, loc, first):
		n = len(nums)
		if n == 1:
			return loc
		if n == 2:
			if nums[0] > nums[1]:
				return loc + 1
			else:
				return 0
		
		if nums[n / 2] > first:
			loc = self.findMin(nums[n/2:], loc + n/2, first)
		else:
			loc = self.findMin(nums[:(n/2 + 1)], loc, first)
		return loc

	def binSearch(self, nums, target, loc):
		n = len(nums)
		print nums
		if n == 1:
			return loc if nums[0] == target else - 1
		if nums[n / 2] > target:
			loc = self.binSearch(nums[:n / 2], target, loc)
		else:
			loc = self.binSearch(nums[n / 2:], target, loc + n / 2)
		return loc
	

def main():
    s = Solution()
    print s.search([4,5,6,1,2,3], 4)


if __name__ == "__main__":
    main()
