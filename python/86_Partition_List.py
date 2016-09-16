#!/usr/bin/python


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def partition(self, head, x):
        lt = ListNode(0)
        ge = ListNode(0)
        geHead = ge
        lt.next = head
        head = lt

        while lt.next:
        	if lt.next.val < x:
        		lt = lt.next
        	else:
        		ge.next = lt.next
        		lt.next = lt.next.next
        		ge = ge.next
        		ge.next = None

        lt.next = geHead.next
        return head.next
        	



def main():
    s = Solution()

if __name__ == "__main__":
    main()
