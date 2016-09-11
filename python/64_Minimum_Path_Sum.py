#!/usr/bin/python

class Solution(object):
    def minPathSum(self, grid):
    	m = len(grid)
    	n = len(grid[0])
        dp = [[0] * n for i in range(m)]
        dp[0][0] = grid[0][0]
        for i in range(m - 1):
        	dp[i + 1][0] = dp[i][0] + grid[i + 1][0]
        for j in range(n - 1):
        	dp[0][j + 1] = dp[0][j] + grid[0][j + 1]
        for i in range(m - 1):
        	for j in range(n - 1):
        		dp[i + 1][j + 1] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i + 1][j + 1]
        return dp[m - 1][n - 1]

def main():
    s = Solution()
    grid = [[1,2,3], [4, 2, 1]]

    print s.minPathSum(grid)

if __name__ == "__main__":
    main()