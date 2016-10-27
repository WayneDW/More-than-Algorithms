#!/usr/bin/python
import unittest

class Solution(object):
    def solveNQueens(self, n):
        def isValid(irow, icol, cols):
            for row, col in enumerate(cols):
                # diff cols and diags...
                if icol == col or abs(irow - row) == abs(icol - col):
                    return False
                #if icol == col or abs(irow - icol) == abs(row - col): # [3,2] and [0, 1]
            return True
        def dfs(irow, cols, sol):
            if irow == n:
                allSol.append(sol)
                return
            for icol in range(n):
                if isValid(irow, icol, cols):
                    row = ['.'] * n
                    row[icol] = 'Q'
                    #sol.append("".join(row)) # important, this way leads to the change of final solution
                    dfs(irow + 1, cols + [icol], sol + ["".join(row)])
                    #sol.pop()

        # save coordinate of the columns
        allSol = []
        dfs(0, [], [])
        return allSol


def main():
    s = Solution()
    print s.solveNQueens(4)


if __name__ == "__main__":
    main()
