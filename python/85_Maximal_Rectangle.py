#!/usr/bin/python
import unittest

'''
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
first use dp


'''

class Solution(object):
    def maximalRectangle(self, matrix):
    	m = len(matrix)
    	if m: 
    		n = len(matrix[0])
    		if n == 0: return 0
    	else:
    		return 0
    	dp = [0] * n
    	for j in range(n):
    		if matrix[0][j] == "1":
    			dp[j] = 1
    	maxS = self.largestRectangleArea(dp) # trival bug in the following function
    	dp.remove(-1)
    	for i in range(1, m):
    		for j in range(n):
    			if matrix[i][j] == "1":
    				dp[j] = dp[j] + 1
    			else: dp[j] = 0
    		maxS = max(maxS, self.largestRectangleArea(dp))
    		dp.remove(-1)
    	return maxS
    def largestRectangleArea(self, heights):
    	if heights == []: return 0
    	maxArea = heights[0]
    	stk = []
    	heights.append(-1)
    	heights = [-1] + heights # make sure stk always has a 0
        for i in range(len(heights)):
        	while stk and heights[i] <= heights[stk[-1]]:
        		minH = heights[stk[-1]]
        		stk.pop()        	
        		if stk: # when it comes to the last item, both minH and height[i] can be -1, so stk is empty
        			maxArea = max(maxArea, (i - stk[-1] - 1) * minH)
        	stk.append(i)
        heights.remove(-1)
        heights.remove(-1)
        return maxArea







class TestSolution(unittest.TestCase):
    def setUp(self):
        self.s = Solution()

    def test_method(self):
        """Such as self.assertEqual, self.assertTrue"""
        self.assertEqual(self.s.maximalRectangle(["10100","10111","11111","10010"]), 6)
        pass

def main():
    s = Solution()


if __name__ == "__main__":
    unittest.main()
