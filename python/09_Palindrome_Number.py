#!/usr/bin/python
import sys
import os
from math import log

class Solution:
    def isPalindrome(self, x):
        if x < 0:
            return False
        exp = 1
        while x / 10 ** exp > 0:
            exp += 1
        while x:
            left = x / 10 ** (exp - 1)
            right = x % 10
            if left != right:
                return False
            x = x % (10 ** (exp - 1)) / 10
            exp -= 2
        return True
            
        



def main():
    s = Solution()
    print s.isPalindrome(1478118741)
if __name__ == "__main__":
    main()
