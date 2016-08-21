#!/usr/bin/python
import sys
import os

class Solution(object):
    def removeElement(self, nums, val):
        n = len(nums);
        i, j = 0, 0
        while i < n - j:
        	if nums[i] == val:
        		nums.remove(nums[i])
        		j += 1
        	else:
        		i += 1
        return len(nums)


def main():
    s = Solution()
    print s.removeElement([1, 2, 2, 3], 2)

if __name__ == "__main__":
    main()
