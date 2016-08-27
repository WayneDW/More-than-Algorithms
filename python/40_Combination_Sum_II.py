#!/usr/bin/python
import sys
import os

class Solution(object):
    def combinationSum2(self, num, target):
        num = sorted(num)
        part, res = [], []
        res = self.dfs(num, target, part, res)
        # delete duplicates
        last, i = "None", 0
        res = sorted(res)
        while i < len(res):
        	if res[i] == last:
        		res.remove(res[i])
        	else:
        		last = res[i]
        		i += 1
        return res

    def dfs(self, num, target, part, res):
    	if target == 0:
    		res.append(part)
    	n = len(num)
    	for i in range(n):
    		if num[i] > target:
    			break
    		self.dfs(num[(i + 1):n], target - num[i], part + [num[i]], res)
    	return res

def main():
    s = Solution()
    vec = [1]
    target = 1
    print s.combinationSum2(vec, target)

if __name__ == "__main__":
    main()
