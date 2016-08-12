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
		res = [""]
		for num in range(len(digits)):
			tmp = []
			for i in res:
				for j in Lists[digits[num]]:
					tmp.append(i + j)
			res = tmp
			'''
			# Never use such loops, otherwise there will be infinite loops
			for i in res:
				for j in Lists[digits[num]]:
					res.append(i + j)
			'''
		if digits == "":
			res.remove("")
		return res


def main():
    s = Solution()
    print s.letterCombinations("")

if __name__ == "__main__":
    main()
