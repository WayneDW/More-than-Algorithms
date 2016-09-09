#!/usr/bin/python
import sys
import os

class Solution(object):
    def deleteDuplicates(self, head):
    	if (not head or not head->next)
    		return head
        p = ListNode(0)
        p.next = head
        left = p
        right = head
        tag = 0
        while right:
        	if right.next and right.next.val == right.val:
        		right.next = right.next.next
        		tag = 1
        	elif tag:
        		left.next = right.next
        		right = right.next
        		tag = 0
        	else:
        		left = right
        		right = right.next
        return p.next




def main():
    s = Solution()

if __name__ == "__main__":
    main()
