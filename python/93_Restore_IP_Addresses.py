#!/usr/bin/python
import unittest

'''
For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
'''

class Solution(object):
    def restoreIpAddresses(self, s):
        if len(s) > 12 or len(s) == 0:
        	return []
        res = []
        self.dfs(s, 0, 0, "", res)
        return res

    def dfs(self, s, idx, pos, subStr, res): # idx-th comma
    	if idx > 3 or pos >= len(s):
    		return
    	if idx == 3 and int(s[pos:]) < 256:
    		if pos < len(s) - 1 and s[pos] == '0':
    			return
    		res.append(subStr[1:] + "." + s[pos:])
    		return
    	
    	self.dfs(s, idx + 1, pos + 1, subStr + "." + s[pos], res)
    	if s[pos] != '0':
    		self.dfs(s, idx + 1, pos + 2, subStr + "." + s[pos : pos + 2], res)
    	if int(s[pos : pos+3]) < 256 and s[pos] != '0':
    		self.dfs(s, idx + 1, pos + 3, subStr + "." + s[pos : pos + 3], res)



        


class TestSolution(unittest.TestCase):
    def setUp(self):
        self.s = Solution()
        #print self.s.restoreIpAddresses("25525511135")

    def test_method(self):
        """Such as self.assertEqual, self.assertTrue"""
        self.assertEqual(self.s.restoreIpAddresses("25525511135"), ["255.255.11.135", "255.255.111.35"])
        self.assertEqual(self.s.restoreIpAddresses("010010"), ["0.10.0.10","0.100.1.0"])


if __name__ == "__main__":
    unittest.main()