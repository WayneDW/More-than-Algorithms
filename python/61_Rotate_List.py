#!/usr/bin/python

class Solution(object):
    def rotateRight(self, head, k):
        if not head:
        	return head
        n = 0
        p, q = head, head
        while head:
        	n += 1
        	if p.next:
        		p = p.next
        	else:
        		break
        if k == n:
        	return head
        else:
        	p.next = head
        k = k % n
        for i in range(1, n - k):
        	q = q.next
        head = q.next
        q.next = None
        return head
        


def main():
    s = Solution()

if __name__ == "__main__":
    main()