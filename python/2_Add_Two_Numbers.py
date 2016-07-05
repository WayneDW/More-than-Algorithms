class Solution(object):
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