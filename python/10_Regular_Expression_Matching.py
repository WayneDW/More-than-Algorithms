#!/usr/bin/python
import sys
import os

class Solution:
    # @return a boolean
    def isMatch(self, s, p):
    	m = len(s)
    	n = len(p)
        dp = [[False for i in range(n + 1)] for j in range(m + 1)]
        dp[0][0] = True

        for i in range(0, m + 1):
            for j in range(1, n + 1):
                if i > 0 and p[j - 1] == '.':
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j - 1] == '*':
                    if i == 0 and j > 1:
                        dp[i][j] = dp[i][j - 2]
                    if i != 0:
                        dp[i][j] = dp[i][j - 1] or dp[i][j - 2] or (dp[i - 1][j] and (s[i - 1]==p[j - 2] or p[j - 2]=='.'))
                elif i > 0:
                    dp[i][j]=dp[i-1][j-1] and s[i-1]==p[j-1]
        return dp[m][n]


def main():
    s = Solution()
    print s.isMatch("abc","bc")

if __name__ == "__main__":
    main()
