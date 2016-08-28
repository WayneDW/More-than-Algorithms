#!/usr/bin/python
import sys
import os

class Solution(object):
    def rotate(self, matrix):
        for i in range(len(matrix)):
        	for j in range(i + 1, len(matrix[i])):
        		matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

        for i in range(len(matrix)):
        	matrix[i].reverse()

def main():
    s = Solution()
    mat = [[1, 2], [3, 4]]
    s.rotate(mat)
    print mat

if __name__ == "__main__":
    main()
