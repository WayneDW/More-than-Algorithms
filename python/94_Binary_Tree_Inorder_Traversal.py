#!/usr/bin/python
import unittest


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        tmp = root
        res, stk = [], []
        while tmp or stk != []:
        	if tmp:
        		stk.append(tmp)
        		tmp = tmp.left
        	else:
        		tmp = stk[-1]
        		stk.pop()
        		res.push_back(tmp.val)
        		tmp = tmp.right
        return res


class TestSolution(unittest.TestCase):
    def setUp(self):
        self.s = Solution()

    def test_method(self):
        """Such as self.assertEqual, self.assertTrue"""
        pass


if __name__ == "__main__":
    unittest.main()