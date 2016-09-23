#!/usr/bin/python
import unittest

class Solution(object):
    def generateTrees(self, n):
        if n == 0:
            return []
        return self.dfs(1, n)
    
    def dfs(self, Tmin, Tmax):
    	if Tmin > Tmax:
    		return [None]
    	resList = []
    	# generate leftSubTree and rightSubTree
    	for k in range(Tmin, Tmax + 1):
    		leftSubTree = self.dfs(Tmin, k - 1)
    		rightSubTree = self.dfs(k + 1, Tmax)

	    	for i in leftSubTree:
	    		for j in rightSubTree:
	    			rootNote = TreeNode(k)
	    			rootNote.left = i
	    			rootNote.right = j
	    			resList.append(rootNote)
    	return resList
        


class TestSolution(unittest.TestCase):
    def setUp(self):
        self.s = Solution()

    def test_method(self):
        """Such as self.assertEqual, self.assertTrue"""
        self.assertEqual(self.s.numTrees(1), 1)
        self.assertEqual(self.s.numTrees(2), 2)
        pass


if __name__ == "__main__":
    unittest.main()