#!/usr/bin/python
import sys
import os

# no need to use #47 to generate all permutations
'''
class Solution(object):
    def groupAnagrams(self, strs):
        k, res = 0, []
        while len(strs) > 0:
			tmp = []
			tmp.append(strs[0])
			listC, listHash = self.permuteUnique(strs[0]), {}
			strs.remove(strs[0])
			if len(strs) == 0:
				res.append(tmp)
				break
			for i in range(len(listC)):
				listHash["".join(listC[i])] = 0
			i = 0
			#print strs
			while i < len(strs):
				if strs[i] in listHash:
					tmp.append(strs[i])
					strs.remove(strs[i])
				else:
					i += 1
			res.append(tmp)
			k += 1
        return res

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
'''

'''
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
'''

class Solution(object):
    def groupAnagrams(self, strs):
    	dt, n, res = {}, len(strs), []

    	for i in range(n):
    		sortedWord = "".join(sorted(strs[i]))
    		if sortedWord in dt:
    			dt[sortedWord].append(strs[i])
    		else:
    			dt[sortedWord] = [strs[i]]

    	for wd in dt:
    		res.append(dt[wd])
    	return res

def main():
    s = Solution()
    print s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])

if __name__ == "__main__":
    main()
