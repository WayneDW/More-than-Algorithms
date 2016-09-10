#!/usr/bin/python
import sys
import os

'''
For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
'''

class Solution(object):
    def maxSubArray(self, nums):
		# dp[i] : the sum of the maximum subarray ended at i
		n = len(nums)
		if not n:
			return None
		dp = [0 for i in range(n)]
		dp[0] = nums[0]
		maxSum = nums[0]
		for i in range(1, n):
			dp[i] = dp[i - 1] + nums[i] if dp[i - 1] > 0 else nums[i]
			maxSum = max(maxSum, dp[i])
		return maxSum
		


def main():
    s = Solution()
    nums = [-2,1,-3,4,-1,2,1,-5,4]
    print s.maxSubArray(nums)

if __name__ == "__main__":
    main()
