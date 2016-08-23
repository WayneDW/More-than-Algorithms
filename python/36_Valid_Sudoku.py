#!/usr/bin/python
import sys
import os

class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        row, col, grid = {}, {}, {}
        for i in range(9):
            row[i], col[i], grid[i] = [], [], []
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    continue
                num = i / 3 * 3 + j / 3
                if board[i][j] in col[j] or board[i][j] in row[i] or board[i][j] in grid[num]:
                    return False
               
                row[i].append(board[i][j])
                col[j].append(board[i][j])
                grid[num].append(board[i][j])
        return True


def main():
    s = Solution()

if __name__ == "__main__":
    main()
