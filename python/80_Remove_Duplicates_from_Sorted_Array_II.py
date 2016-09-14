#!/usr/bin/python

'''
[1,1,1,2,2,3], return 5
'''

class Solution(object):
    def removeDuplicates(self, nums):
    	n = len(nums)
    	if n < 3:
    		return n
    	total = 2
    	i = 2
    	while i < n:
    		if nums[i] == nums[i - 2]:
    			nums.remove(nums[i])
    			n -= 1
    			continue
    		total += 1
    		i += 1	
    	return total

def main():
    s = Solution()
    print s.removeDuplicates([1,1,1,2])

if __name__ == "__main__":
    main()
