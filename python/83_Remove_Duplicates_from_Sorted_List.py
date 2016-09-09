#!/usr/bin/python
import sys
import os

class Solution(object):
    def deleteDuplicates(self, head):
        if head == None:
            return head
        tmp = head
        while tmp.next:
            if tmp.next.val == tmp.val:
                tmp.next = tmp.next.next
            else:
                tmp = tmp.next
        return head





def main():
    s = Solution()

if __name__ == "__main__":
    main()
