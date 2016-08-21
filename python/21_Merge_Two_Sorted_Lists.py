#!/usr/bin/python
import sys
import os

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        head = ListNode(0)
        tmp = head
        while l1 and l2:
        	if l1.val < l2.val:
        		tmp.next = l1
        		l1 = l1.next
        	else:
        		tmp.next = l2
        		l2 = l2.next
            tmp = tmp.next
        tmp.next = l1 if l1 else l2
        return head.next

def main():
    s = Solution()

if __name__ == "__main__":
    main()
