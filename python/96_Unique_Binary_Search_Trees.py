#!/usr/bin/python
import unittest



class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        dp = [0] * (n + 1)
        dp[0] = 1
        for i in range(1, n + 1):
        	for j in range(i):
        		dp[i] += dp[j] * dp[i - 1 - j]
        return dp[n]


class TestSolution(unittest.TestCase):
    def setUp(self):
        self.s = Solution()

    def test_method(self):
        """Such as self.assertEqual, self.assertTrue"""
        #self.assertEqual(self.s.)
        pass


if __name__ == "__main__":
    unittest.main()
