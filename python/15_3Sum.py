#!/usr/bin/python
import sys
import os

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        n = len(nums)
        if n < 3:
        	return []
        nums = sorted(nums)
        '''
        The following code will get the time limit exceeded
        for i in range(n):
        	for j in range(i + 1, n):
        		twoSum = -(nums[i] + nums[j])
        		#print nums[i], nums[j], twoSum, twoSum in nums
        		if twoSum in nums:
        			if (twoSum != nums[i] and twoSum != nums[j]) or (nums.count(nums[i]) > 1 and nums.count(nums[j]) > 1):
        				tp = tuple(sorted([nums[i], nums[j], twoSum]))
        				if tp not in List:
        					List.append(tp)
        if nums.count(0) < 3 and (0, 0, 0) in List:
            List.remove((0, 0, 0))
        '''
        List = []
        for i in range(n - 2):
        	left = i + 1
        	right = n - 1
        	# strange logic, ignore this line, but TLE without it.
        	if i == 0 or nums[i] > nums[i - 1]:
        		while left < right:
        			print i, nums[i], nums[left], nums[right]
        			if nums[left] + nums[right] == -nums[i]:
        				List.append([nums[i], nums[left], nums[right]])
        				left += 1
        				right -= 1
        				while left < right and nums[right] == nums[right + 1]:
        					right -= 1
        				while left < right and nums[left] == nums[left - 1]:
        					left += 1
        			elif nums[i] + nums[left] < -nums[right]:
        				while left < right:
        					right -= 1
        					# equavalent to get rid of repeat
        					if nums[right] < nums[right + 1]:
        						break
        			else:
        				while left < right:
        					left += 1
        					if nums[left] > nums[left - 1]:
        						break

        return List

def main():
    s = Solution()
    print s.threeSum([-1,0,1,2,-1,-4])
if __name__ == "__main__":
    main()
