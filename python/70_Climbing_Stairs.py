#!/usr/bin/python
import sys
import os

'''
You are climbing a stair case. It takes n steps to reach to the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
'''

class Solution(object):
    def climbStairs(self, n):
    	# dp i: number of ways to climb to a i-stair
    	if n <= 2:
    		return n
    	dp = [0 for i in range(n + 1)]
    	dp[1], dp[2] = 1, 2
    	for i in range(3, n + 1):
    		#print i
    		dp[i] = dp[i - 1] + dp[i - 2]
    	return dp[n]



def main():
    s = Solution()
    print s.climbStairs(4)

if __name__ == "__main__":
    main()
