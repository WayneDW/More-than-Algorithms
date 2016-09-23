#!/usr/bin/python
import unittest



# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def isSameTree(self, p, q):
    	if p == q == None: # not enough, since different addresses may have the same value
    		return True
    	elif (p == None and q != None) or (p != None and q == None):
    		return False
    	elif p.val == q.val:
    		resLeft = self.isSameTree(p.left, q.left)
    		resRight = self.isSameTree(p.right, q.right)
    		if resRight and resLeft:
    			return True
    	return False




class TestSolution(unittest.TestCase):
    def setUp(self):
        self.s = Solution()

    def test_method(self):
        """Such as self.assertEqual, self.assertTrue"""
        #self.assertEqual(self.s.)
        # [10,5,15], [10,5,null,null,15]
        # 0
        pass

def main():
	s = Solution()

	a1 = TreeNode(10)
	a2 = TreeNode(5)
	a3 = TreeNode(15)
	a1.left = a2
	a1.right = a3

	b1 = TreeNode(10)
	b2 = TreeNode(5)
	b3 = TreeNode(None)
	b4 = TreeNode(None)
	b5 = TreeNode(15)
	b1.left = b2
	b1.right = b3
	b2.left = b4
	b2.right = b5

	print s.isSameTree(a1, b1)


if __name__ == "__main__":
    #unittest.main()
    main()
