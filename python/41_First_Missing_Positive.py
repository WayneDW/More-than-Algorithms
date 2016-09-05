#!/usr/bin/python
import sys
import os

class Solution(object):
    def firstMissingPositive(self, A):
    	i, n = 0, len(A)
    	if n == 0:
    	    return 1
    	while i < n:
    		if A[i] != i + 1 and A[i] > 0 and A[i] < n and A[A[i] - 1] != A[i]:
    			A[A[i] - 1], A[i] = A[i], A[A[i] - 1]
    		else:
    			i += 1
    	for i in range(n):
    		if A[i] != i + 1:
    			return i + 1
    	return n + 1


def main():
    s = Solution()
    print s.firstMissingPositive([3,4,-1,1])

if __name__ == "__main__":
    main()
