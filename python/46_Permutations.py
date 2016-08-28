#!/usr/bin/python
import sys
import os

class Solution:
	def permute(self, num):
		n, res = len(num), []
		if n <= 1:
			return [num]
		for i in range(n):
			for j in self.permute(num[:i] + num[(i + 1):]):
				res.append([num[i]] + j)
		return res



def main():
    s = Solution()
    a = [1, 2, 3]
    print s.permute(a)

if __name__ == "__main__":
    main()
