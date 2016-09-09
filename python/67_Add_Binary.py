#!/usr/bin/python
import sys
import os

'''
a = "11"
b = "1"
Return "100".
'''

class Solution(object):
    def addBinary(self, a, b):
        if (len(a) < len(b)):
        	return self.addBinary(b, a)
        
        m, n = len(a), len(b)
        carry = 0
        res = []
        for i in range(m):
        	if i > n - 1:
        		total = int(a[m - 1 -i]) + int(carry)
        	else:
        		total = int(a[m - 1 -i]) + int(b[n - 1 -i]) + carry
        	carry = total / 2
        	#print i, a[i], b[], total, total % 2
        	res.append(str(total % 2))
        res = "".join(res)
        res = res[::-1]
        if carry:
        	res = "1" + res
        return res
        

def main():
    s = Solution()
    print s.addBinary("1010", "1011")

if __name__ == "__main__":
    main()
