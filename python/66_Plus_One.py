#!/usr/bin/python
import sys
import os

class Solution(object):
    def plusOne(self, digits):
    	carry = 1
    	for i in range(len(digits) - 1, -1, -1):
    		sums = carry + digits[i]
    		carry = sums / 10
    		digits[i] = sums % 10
    	if carry:
    		digits = [1] + digits
    	return digits


def main():
    s = Solution()

if __name__ == "__main__":
    main()
