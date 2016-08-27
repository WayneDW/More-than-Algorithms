#!/usr/bin/python
import sys
import os


#https://www.nayuki.io/page/next-lexicographical-permutation-algorithm
class Solution(object):
    def nextPermutation(self, nums):
		n = len(nums)
		if n < 2:
			return
		i = n - 2
		while i >= 0 and nums[i] >= nums[i + 1]:
			i -= 1
		if i < 0:
			nums.reverse()
			return
		j = i + 1
		while j < n and nums[j] > nums[i]:
			j += 1
		j -= 1
		print nums, i, j
		nums[i], nums[j] = nums[j], nums[i]
		print nums
		nums[i + 1: n] = nums[i + 1: n][::-1]
		return


def main():
	s = Solution()
	nums = [0, 1, 2, 5, 3, 3, 0]
	#nums = [1, 2]
	s.nextPermutation(nums)
	print nums


if __name__ == "__main__":
    main()
