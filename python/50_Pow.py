#!/usr/bin/python
import sys
import os

class Solution(object):
    def myPow(self, x, n):
        if n == 0:
        	return 1
        if n < 0:
        	return 1 / self.myPow(x, -n)
        if n == 1:
        	return x
        out = self.myPow(x, n / 2)
        out *= out
        if n % 2 == 1:
        	out *= x
        return out


def main():
    s = Solution()
    print s.myPow(34.00515, -3)

if __name__ == "__main__":
    main()
