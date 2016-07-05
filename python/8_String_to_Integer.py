#!/usr/bin/python
import sys
import os
import re

class Solution:
    def myAtoi(self, str):
        INT_MAX = 2 ** 31 - 1
        INT_MIN = -2 ** 31
        str = str.strip().split(" ")[0]
        if len(str) == 0:
            return 0
        # tag is used for counting the start point
        tag = 0
        n = len(str)
        num = 0
        if str[0] == '-':
            tag = -1
        elif str[0] == '+':
            tag = 1
        for i in xrange(abs(tag), n):
            if str[i].isdigit():
                num = 10 * num + int(str[i])
            else:
                break
        if tag == -1:
            return max(tag * num, INT_MIN)
        else:
            return min(num, INT_MAX)
            
            
            


def main():
    s = Solution()
    print s.myAtoi("  -0012a41   ")

if __name__ == "__main__":
    main()
