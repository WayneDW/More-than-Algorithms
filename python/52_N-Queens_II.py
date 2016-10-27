#!/usr/bin/python
import unittest



class Solution(object):
    def totalNQueens(self, n):
        def isValid(irow, icol, cols):
            for row, col in enumerate(cols):
                if icol == col or abs(irow - row) == abs(icol - col):
                    return False
            return True
        def dfs(irow, cols):
            if irow == n:
                allSol[0] += 1
                return
            for icol in range(n):
                if isValid(irow, icol, cols):
                    dfs(irow + 1, cols + [icol])

        allSol = [0]
        dfs(0, [])
        return allSol[0]




def main():
    s = Solution()
    print s.totalNQueens(4)


if __name__ == "__main__":
    main()
