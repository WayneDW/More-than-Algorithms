#!/usr/bin/python

class Solution(object):
    def sortColors(self, nums):
    	n = len(nums)
        i, left, right = 0, 0, n - 1
        while i < n:
        	tmp = nums[i]
        	if nums[i] == 0 and i >= left:
        		nums[left], nums[i] = tmp, nums[left]
        		left += 1
        		i += 1
        	elif nums[i] == 2 and i < right:
        		nums[right], nums[i] = tmp, nums[right]
        		right -= 1
        	else:
        		i += 1
def main():
	s = Solution()
	num = [2]
	s.sortColors(num)
	print num

if __name__ == "__main__":
    main()
