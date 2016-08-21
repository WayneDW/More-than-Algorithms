#!/usr/bin/python
import sys
import os

class Solution:
    def reverse(self, start, end):
        newhead = ListNode(0)
        newhead.next = start
        while newhead.next != end:
            tmp = start.next
            start.next = tmp.next
            tmp.next = newhead.next
            newhead.next = tmp
        return [end, start]
    def reverseKGroup(self, head, k):
        if head == None:
        	return None
        nhead = ListNode(0)
        nhead.next = head
        start = nhead
        while start.next:
            end = start
            for i in range(k-1):
                end = end.next
                if end.next == None:
                	return nhead.next
            start.next, start =self.reverse(start.next, end.next)
        return nhead.next

def main():
    s = Solution()

if __name__ == "__main__":
    main()
