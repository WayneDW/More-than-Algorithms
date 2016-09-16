#!/usr/bin/python
import sys
import os

# the worst case of this method can be o(n2), no extra method needed
class Solution(object):
    def merge(self, nums1, m, nums2, n):
        i, j, shift = [0] * 3
        while i < m + j and j < n:
            tmp = nums1[i]
            if nums2[j] < nums1[i]:
            	for k in range(m + j, i, -1):
            		nums1[k] = nums1[k - 1]
            	nums1[i] = nums2[j]
            	j += 1
            else:
            	i += 1
        if m == 0:
            for i in range(n):
                nums1[i] = nums2[i]
        else:
        	for i in range(m + j, m + n):
        		nums1[i] = nums2[i - m]

# we can also create a temp array with space o(m + n)

def main():
    s = Solution()
    num1 = [4,5,9,11,0,0,0,0,0,0,0,0,0]
    num2 = [1,3,6,15]
    s.merge(num1, 4, num2, 4)
    print num1

if __name__ == "__main__":
    main()
