#!/usr/bin/python

class Solution(object):
    def mySqrt(self, x):
    	if x < 1:
    		return 0
    	elif x < 4:
    		return 1
    	left, right = 1, x
    	while left < right - 1:
    		mid = (left + right) / 2
    		if mid ** 2 == x:
    			return mid
    		if mid ** 2 > x:
    			right = mid
    		else:
    			left = mid
    	return left


def main():
    s = Solution()
    print s.mySqrt(16)

if __name__ == "__main__":
    main()