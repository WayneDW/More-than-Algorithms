#!/usr/bin/python
import sys
import os

class Solution(object):
    def permuteUnique(self, nums):
        n, res = len(nums), []
        if n <= 1:
        	return [nums]

        nums, last = sorted(nums), "."
        for i in range(n):
        	if last == nums[i]:
        		continue
        	for arr in self.permuteUnique(nums[:i] + nums[i + 1:]):
        		res.append(arr + [nums[i]])
        	last = nums[i]
        return res


        


def main():
    s = Solution()
    print s.permuteUnique([1, 1, 2])

if __name__ == "__main__":
    main()
