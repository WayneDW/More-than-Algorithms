#!/usr/bin/python
import sys
import os
import math

class Solution:
    def reverse(self, x):
        sign = 1 if x > 0 else -1
        output = 0
        x = abs(x)
        while x:
            if output > 214748364:
                return 0;
            output = 10 * output + x % 10
            x /= 10
        return sign * output


def main():
    s = Solution()
    print s.reverse(1)

if __name__ == "__main__":
    main()
