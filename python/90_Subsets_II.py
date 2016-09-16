#!/usr/bin/python

class Solution(object):
    def subsetsWithDup(self, nums):
    	n = len(nums)
    	nums = sorted(nums)
    	res = [[]]
    	part = []
    	def dfs(nums, part):
    		if len(nums) == 0:
    			return
    		i, last = 0, "*"
    		for i in range(len(nums)):
    			if nums[i] == last:
    				continue
    			# can't append part first
    			# since it would transfer address rather than value
    			# so once innter list changes, res change too
    			# part.append(nums[i])
    			res.append(part + [nums[i]]) 
    			dfs(nums[i + 1:], part + [nums[i]])
    			last = nums[i]
    	dfs(nums, part)
    	return res

def main():
    s = Solution()
    print s.subsetsWithDup([1,2,2])


if __name__ == "__main__":
    main()
