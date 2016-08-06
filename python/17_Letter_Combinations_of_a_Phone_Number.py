#!/usr/bin/python
import sys
import os

'''
Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
'''

class Solution(object):
	def letterCombinations(self, digits):
		Lists = {'2':['a','b','c'], 
				 '3':['d','e','f'],
                 '4':['g','h','i'],
                 '5':['j','k','l'],
                 '6':['m','n','o'],
                 '7':['p','q','r','s'],
                 '8':['t','u','v'],
                 '9':['w','x','y','z']
				 }
		res = []
		def update(res, par):
			tmp = []
			for i in res:
				for j in par:
					tmp.append(i + j)
			return tmp
		for num in range(len(digits)):
			if num == 0:
				for i in Lists[digits[num]]:
					res.append(i)

			else:
				res = update(res, Lists[digits[num]])
				'''
				# Never use such loops, otherwise there will be infinite loops
				for i in res:
					for j in Lists[digits[num]]:
						res.append(i + j)
				'''

		return res


def main():
    s = Solution()
    print s.letterCombinations("23")

if __name__ == "__main__":
    main()
