#!/usr/bin/python

'''
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
'''

class Solution(object):
    def searchMatrix(self, matrix, target):
		m = len(matrix)
		n = len(matrix[0])
		left, right = 0, m * n - 1

		while left <= right:
			mid = (left + right) / 2
			i0 = mid / n
			j0 = mid % n
			if matrix[i0][j0] == target:
				return True
			elif matrix[i0][j0] < target:
				left = mid + 1
			else:
				right = mid - 1
		return False


        

def main():
    s = Solution()
    matrix = [ [1,   3,  5,  7], [10, 11, 16, 20], [23, 30, 34, 50]]
    #matrix = [[1, 2, 4]]
    print s.searchMatrix(matrix, 4)

if __name__ == "__main__":
    main()
