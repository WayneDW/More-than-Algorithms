#!/usr/bin/python
import sys
import os

'''
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
'''

class Solution(object):
    # Linked list
    def addTwoNumbers(self, l1, l2):
        head = ListNode(0)
        l = head
        carry = 0
        while carry or l1 or l2:
            carry, sum = 0, carry
            if l1:
                sum += l1.val
                l1 = l1.next
            if l2:
                sum += l2.val
                l2 = l2.next
            if sum > 9:
                sum -= 10
                carry = 1
            l.next = ListNode(sum)
            l = l.next
        return head.next


def main():
    s = Solution()

if __name__ == "__main__":
    main()
