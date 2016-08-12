#!/usr/bin/python
import sys
import os

'''
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
'''

class Solution(object):
    def twoSum(self, nums, target):
        d = {}
        # set key as default if the key is not in dict
        for num, dat in enumerate(nums):
            d.setdefault(dat,[]).append(num)

        for num in d:
            if target - num in nums and target - num == num:
                return d[num]
            elif target - num in nums and target - num != num:
                return sorted([d[num][0], d[target - num][0]])


def main():
    s = Solution()
    print s.twoSum([2, 7, 11, 15], 9)

if __name__ == "__main__":
    main()
