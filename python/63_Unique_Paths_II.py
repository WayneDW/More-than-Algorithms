#!/usr/bin/python

 
class Solution(object):
	def uniquePathsWithObstacles(self, obstacleGrid):
		m = len(obstacleGrid)
		n = len(obstacleGrid[0])
		dp = [[0] * n for i in range(m)]
		dp[0][0] = 1 - obstacleGrid[0][0]
		for i in range(1, n):
			dp[0][i] = dp[0][i - 1] * (1 - obstacleGrid[0][i])
		for i in range(1, m):
			dp[i][0] = dp[i - 1][0] * (1 - obstacleGrid[i][0])
		for i in range(m - 1):
			for j in range(n - 1):
				dp[i + 1][j + 1] = dp[i + 1][j] * (1 - obstacleGrid[i + 1][j]) + dp[i][j + 1] * (1 - obstacleGrid[i][j + 1])
		return dp[m - 1][n - 1] * (1 - obstacleGrid[m - 1][n - 1])
               


def main():
    s = Solution()
    #obstacleGrid = [[0,0,0], [0,1,0],[0,0,0]]
    obstacleGrid = [[1]]
    print s.uniquePathsWithObstacles(obstacleGrid)

if __name__ == "__main__":
    main()