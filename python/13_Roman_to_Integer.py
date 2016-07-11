#!/usr/bin/python
import sys
import string
import os

class Solution:
	def romanToInt(self, s):
		values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
		numerals = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
		out = 0
		for i in range(13):
			while s.startswith(numerals[i]):
			    # use replace for a string and pop or remove for a list
				s = string.replace(s, numerals[i], '', 1)
				out += values[i]
		return out



def main():
    s = Solution()
    s.romanToInt("DCXXI")

if __name__ == "__main__":
    main()
