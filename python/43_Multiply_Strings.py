#!/usr/bin/python
import sys
import os

# TIME LIMIT EXCEEDED
'''
class Solution(object):
    def multiply(self, num1, num2):
    	if num1 == "0" or num2 == "0":
    		return "0"
        shift, m = "0", len(num2)
        out = self.mulTimesSingle(num1, num2[m - 1])
        for i in range(m - 2, -1, -1):
        	res = self.mulTimesSingle(num1, num2[i])
        	out = self.add(res + shift, out)
        	shift += "0"
        return out

    def mulTimesSingle(self, num1, num2):
    	shift, res = 0, ""
    	for i in range(len(num1) - 1, -1, -1):
    		mul = int(num2) * int(num1[i]) + shift
    		digit, shift = mul % 10, mul / 10
    		res = str(digit) + res
    		if i == 0 and shift > 0:
    			res = str(shift) + res
       	return res

    def add(self, num1, num2):
    	n = min(len(num1), len(num2))
    	m = max(len(num1), len(num2))
    	out, shift = "", 0
    	for i in range(n - 1, -1, -1):
    		if len(num1) == m:
    			res = int(num1[i + m - n]) + int(num2[i]) + shift
    		else:
    			res = int(num1[i]) + int(num2[i + m - n]) + shift
    		digit, shift = res % 10, res / 10
    		out = str(digit) + out
    		if n == m and shift > 0 and i == 0:
    			out = str(shift) + out

    	for i in range(m - n - 1, -1, -1):
    		if len(num1) == m:
    			res = shift + int(num1[i])
    		else:
    			res = shift + int(num2[i])
    		digit, shift = res % 10, res / 10
    		out = str(digit) + out
    		if shift > 0 and i == 0:
    			out = str(shift) + out
    	return out
'''

class Solution:
	def multiply(self, num1, num2):
		num1, num2, m, n = num1[::-1], num2[::-1], len(num1), len(num2)
		arr = [0 for i in range(m + n)]
		for i in range(m):
			for j in range(n):
				arr[i + j] += int(num1[i]) * int(num2[j])

		ans = []
		for i in range(m + n):
			digit, carry = arr[i] % 10, arr[i] / 10
			if i != m + n - 1:
				arr[i + 1] += carry
			ans.insert(0, str(digit))
		while ans[0] == '0' and len(ans) > 1:
			del ans[0]
		return "".join(ans)



def main():
    s = Solution()
    num1, num2 = "23", "45"
    print s.multiply(num1, num2)

if __name__ == "__main__":
    main()
