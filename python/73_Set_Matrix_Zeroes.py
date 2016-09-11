#!/usr/bin/python


class Solution(object):
    def setZeroes(self, matrix):
        m = len(matrix)
        n = len(matrix[0])
        tagRow = [0] * m
        tagCol = [0] * n
        for i in range(m):
        	for j in range(n):
        		if matrix[i][j] == 0:
        			tagRow[i], tagCol[j] = 1, 1
       	for i in range(m):
        	for j in range(n):
        		if tagRow[i] or tagCol[j]:
        			matrix[i][j] = 0
        

def main():
    s = Solution()

if __name__ == "__main__":
    main()
