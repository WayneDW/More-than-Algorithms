#!/usr/bin/python
import sys
import os

class Solution(object):
    def divide(self, dividend, divisor):
    	sign = 1
    	if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
    		sign = -1
    	dd, ds = abs(dividend), abs(divisor)
    	if dd < ds:
    		return 0
    	if dividend == -2 ** 31 and divisor == -1:
    		return 2 ** 31 - 1
    	res = 0
    	while ds <= dd:
    		bs_ds = ds # bit shift operator
    		part = 1
    		while not (bs_ds <= dd and bs_ds + bs_ds > dd):
    			bs_ds +=  bs_ds
    			part += part
    		dd -= bs_ds
    		res += part
    	return res * sign

def main():
    s = Solution()
    print s.divide(16, 3)
    print s.divide(-1, 1)

if __name__ == "__main__":
    main()
