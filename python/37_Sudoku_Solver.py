#!/usr/bin/python
import sys
import os

class Solution:
	def solveSudoku(self, board):
		def isValid(x, y):
			tmp = board[x][y]; board[x][y] = '*'
			for i in range(9):
				if board[x][i] == tmp or board[i][y] == tmp:
					return False
			for i in range(3):
				for j in range(3):
					if board[x / 3 * 3 + i][y / 3 * 3 + j] == tmp:
						return False
			board[x][y] = tmp
			return True
		def dfs():
			for i in range(9):
				for j in range(9):
					if board[i][j] == '.':
						for k in '123456789':
							board[i][j] = k
							if isValid(i, j) and dfs():
								return True
							board[i][j] = '.'
						return False
			return True
		dfs()


'''
class Solution(object):
    def solveSudoku(self, board):
        if len(board) == 9 and len(board[0]) == 9:
        	i = self.Sudoku(board, 0, 0)

    def Sudoku(self, board, row, col):
    	if row == 9:
    		return True
    	if col == 8:
    		ROW = row + 1
    		COL = 0
    	else:
    		ROW = row
    		COL = col + 1

    	if board[row][col] != '.':
    		if not self.isValid(board, row, col):
    			return False
    		return self.Sudoku(board, ROW, COL)

    	for i in '123456789':
    		board[row][col] = i # doesn't support recursion
    		if self.isValid(board, row, col) and self.Sudoku(board, ROW, COL):
    			return True
    	board[row][col] = '.'
    	return False

    def isValid(board, row, col):
    	val = board[row][col]
    	for i in range(9):
    		if (board[row][i] == val and i != col) or (board[i][col] == val and i != row):
    			return False
    	row0, col0 = row / 3 * 3, col / 3 * 3
    	for i in range(3):
    		for j in range(3):
    			if (board[row0 + i][col0 + j] == val) and not (row0 + i == row and col0 + j == col):
    				return False
    	return True
'''


def main():
    s = Solution()
    board = ["..9748...","7........",".2.1.9...","..7...24.",".64.1.59.",".98...3..","...8.3.2.","........6","...2759.."]
    s.solveSudoku(board)


if __name__ == "__main__":
    main()
