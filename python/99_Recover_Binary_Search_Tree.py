#!/usr/bin/python
import sys
import os

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def recoverTree(self, root):
    	self.first = None
    	self.second = None
    	self.prev = None
    	self.inorder(root)
    	tmp = self.first.val
    	self.first.val = self.second.val
    	self.second.val = tmp
    	return

    def inorder(self, root):
    	if not root: 
    		return
    	else:
    		self.inorder(root.left)
    		if not self.prev:
    			self.prev = root
    		else:
    			if self.prev.val >= root.val:
    				if not self.first:
    					self.first = self.prev
    				self.second = root
    			self.prev = root
    		self.inorder(root.right)


def main():
    s = Solution()

    t = [TreeNode(i) for i in range(1, 8)]
    t[3].left = t[1]
    t[3].right = t[5]
    t[1].left = t[0]
    t[1].right = t[2]
    t[5].left = t[4]
    t[5].right = t[6]
    print s.recoverTree(t[3])

if __name__ == "__main__":
    main()
