#!/usr/bin/python
import unittest

'''
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
'''

class Solution(object):
    def isInterleave(self, s1, s2, s3):
    	m, n = len(s1), len(s2)
    	dp = [[False] * (n + 1) for i in range(m + 1)]
    	dp[0][0] = True
    	if m + n != len(s3): return False
    	for i in range(m):
    		if s1[i] == s3[i]: dp[i + 1][0] = True
    		else: break
    	for i in range(n):
    		if s2[i] == s3[i]: dp[0][i + 1] = True
    		else: break
    	for i in range(m):
    		for j in range(n):
    			if s3[i + j + 1] == s1[i] and dp[i][j + 1]: 
    				dp[i + 1][j + 1] = dp[i][j + 1]
    			elif s3[i + j + 1] == s2[j] and dp[i + 1][j]:
    				dp[i + 1][j + 1] = dp[i + 1][j]
        return dp[m][n]




class TestSolution(unittest.TestCase):
    def setUp(self):
        self.s = Solution()

    def test_method(self):
        """Such as self.assertEqual, self.assertTrue"""
        s1, s2, s3 = "aabcc", "dbbca", "aadbbcbcac"
        self.assertEqual(self.s.isInterleave(s1, s2, s3), True)
        s3 = "aadbbbaccc"
        self.assertEqual(self.s.isInterleave(s1, s2, s3), False)
        s1, s2, s3 = "a", "", "c"
        self.assertEqual(self.s.isInterleave(s1, s2, s3), False)
        s1, s2, s3 = "a", "b", ""
        self.assertEqual(self.s.isInterleave(s1, s2, s3), False)
        #s1, s2, s3 = "aa", "ab", "abaa" # tricky part, since we want ab to move forward
        #self.assertEqual(self.s.isInterleave(s1, s2, s3), True)
        pass

def main():
    s = Solution()


if __name__ == "__main__":
    unittest.main()
