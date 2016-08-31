#!/usr/bin/python
import sys
import os

class Solution(object):
    def longestValidParentheses(self, s):
        n, maxLen = len(s), 0
        dp = [0 for i in range(n)]
        if n < 2:
        	return 0

        for i in range(1, n):
        	j = i - 2 - dp[i - 1]
        	if j < -1 or s[j + 1] == ')' or s[i] == '(':
        		dp[i] = 0
        	else:
        		dp[i] = dp[j] + 2 + dp[i - 1]
        		maxLen = max(maxLen, dp[i])
        return maxLen

        


def main():
    s = Solution()
    print s.longestValidParentheses(")()())")

if __name__ == "__main__":
    main()
