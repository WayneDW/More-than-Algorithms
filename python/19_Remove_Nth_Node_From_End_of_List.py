#!/usr/bin/python
import sys
import os
from llist import dllist, dllistnode
# https://pythonhosted.org/llist/


class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        first, second = head, head
        i = 0
        while i < n + 1 and first:
        	first = first.next
        	i = i + 1

        if i == n + 1:
        	while first:
        		first = first.next
        		second = second.next
        	second.next = second.next.next
        else:
        	head = head.next
        return head