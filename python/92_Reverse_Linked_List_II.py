#!/usr/bin/python
import unittest


class Solution(object):
    def reverseBetween(self, head, m, n):
    	if m == n:
    		return head
    	p = ListNode(0)
    	p.next = head
    	head = p
    	leftN, rightN = p, p
    	for i in range(m):
    		leftN = leftN.next
    		if i != m - 1:
    			p = p.next
    	for j in range(n):
    		rightN = rightN.next
    	p.next = rightN  # 1->4
    	rightN = rightN.next
    	for i in range(n - m, 0, -1):
    		tmp = leftN
    		for j in range(i - 1, 0, -1):
    			tmp = tmp.next
    		tmp.next.next = tmp
    	leftN.next = rightN # 2->5
    	return head.next
    	



class TestSolution(unittest.TestCase):
    def setUp(self):
        self.s = Solution()

    def test_method(self):
        """Such as self.assertEqual, self.assertTrue"""
        pass


if __name__ == "__main__":
    unittest.main()