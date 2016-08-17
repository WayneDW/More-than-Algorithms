#!/usr/bin/python
import sys
import os

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if len(lists) == 0:
        	return None
        right = len(lists) - 1
        while right > 0:
        	left = 0
        	while left < right:
        		lists[left] = self.two_merge(lists[left], lists[right])
        		left += 1
        		right -= 1
        return lists[0]
    def two_merge(self, l1, l2):
    	head = ListNode(0)
    	out = head
    	while l1 and l2:
    		if l1.val < l2.val:
    			out.next = l1
    			l1 = l1.next
    		else:
    			out.next = l2
    			l2 = l2.next
    		out = out.next
    	out.next = l1 if l1 else l2
    	return head.next


def main():
    s = Solution()

if __name__ == "__main__":
    main()
