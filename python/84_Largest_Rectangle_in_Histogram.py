#!/usr/bin/python
import unittest


class Solution(object):
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
        #print heights
        return maxArea


class TestSolution(unittest.TestCase):
    def setUp(self):
        self.s = Solution()

    def test_method(self):
        """Such as self.assertEqual, self.assertTrue"""
        self.assertEqual(self.s.largestRectangleArea([1, 2, 3, 4, 2]), 8)
        self.assertEqual(self.s.largestRectangleArea([2, 1, 2]), 3)
        self.assertEqual(self.s.largestRectangleArea([5, 4, 1, 2]), 8)
        self.assertEqual(self.s.largestRectangleArea([2, 0, 2]), 2)
        self.assertEqual(self.s.largestRectangleArea([0]), 0)
        pass

def main():
    s = Solution()


if __name__ == "__main__":
    unittest.main()
