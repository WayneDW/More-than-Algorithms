#!/usr/bin/python


class Solution(object):
    def subsets(self, nums):
        num = sorted(nums)
        res = [[]]
        part = []
        def dfs(num, part):
        	if len(num) == 0:
        		return
        	for i, item in enumerate(num):
        		res.append(part + [item])
        		dfs(num[i + 1:], part + [item])
        dfs(num, part)
        return res



def main():
    s = Solution()
    nums = [2,1,3]
    print s.subsets(nums)

if __name__ == "__main__":
    main()
