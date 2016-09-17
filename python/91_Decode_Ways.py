#!/usr/bin/python
import unittest


class Solution:
    def numDecodings(self, s):
    	n = len(s)
        if s == "" or s[0]=='0': return 0
        dp = [0] * (n + 1)
        dp[0:2] = [1,1]
        for i in range(2,len(s)+1):
            if 10 <= int(s[i-2:i]) <=26 and s[i-1] != '0':
                dp[i] = dp[i-1] + dp[i-2]
            elif int(s[i-2:i]) == 10 or int(s[i-2:i]) == 20:
                dp[i] = dp[i-2]
            elif s[i-1] != '0':
                dp[i] = dp[i-1]
            else:
                return 0
        return dp[len(s)]


class TestSolution(unittest.TestCase):
    def setUp(self):
        self.s = Solution()

    def test_method(self):
        """Such as self.assertEqual, self.assertTrue"""
        self.assertEqual(self.s.numDecodings("0"), 0)
        self.assertEqual(self.s.numDecodings("1"), 1)
        self.assertEqual(self.s.numDecodings("01"), 0)
        self.assertEqual(self.s.numDecodings("100"), 0)
        self.assertEqual(self.s.numDecodings("30"), 0)
        self.assertEqual(self.s.numDecodings("101"), 1)
        self.assertEqual(self.s.numDecodings("1212"), 5)
        pass


if __name__ == "__main__":
    unittest.main()
