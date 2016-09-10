#!/usr/bin/python

class Solution(object):
    def uniquePaths(self, m, n):
    	dp = [[0] * (n + 1) for i in range(m + 1)]
    	for i in range(n + 1):
    		dp[1][i] = 1
    	for i in range(1, m + 1):
    		dp[i][1] = 1
    	if m == 1 or n == 1:
    		return 1
    	for i in range(1, m):
    		for j in range(1, n):
    			dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1]
    	return dp[m][n]
        


def main():
    s = Solution()
    print s.uniquePaths(2, 2)

if __name__ == "__main__":
    main()