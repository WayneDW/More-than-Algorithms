#!/usr/bin/python
import sys
import os

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head or not head.next:
            return head
        p = ListNode(0)
        p.next = head
        q = p
        while q.next and q.next.next:
        	tmp = q.next.next
        	# the following 2 lines cannot be interchanged
        	# otherwise q.next.next won't point to the target since tmp.next has changed
        	q.next.next = tmp.next
        	tmp.next = q.next
        	q.next = tmp
        	q = q.next.next
        return p.next




def main():
    s = Solution()

if __name__ == "__main__":
    main()
