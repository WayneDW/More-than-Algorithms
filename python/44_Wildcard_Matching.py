#!/usr/bin/python
import sys
import os


# the hard part is how to deal with *
class Solution(object):
    def isMatch(self, s, p):
        i, j, sloc, star = 0, 0, 0, -1
        while i < len(s):
            if j < len(p) and (s[i] == p[j] or p[j] == "?"):
                i += 1; j += 1
                print "==",i, j
            elif j < len(p) and p[j] == "*":
                star = j
                j += 1
                sloc = i
                print "tag star", star
            elif star != -1:
                j = star + 1
                sloc += 1 # most important part, update past location, do matching again
                i = sloc
                print "update", i, j, sloc
            else:
                return False
        while j < len(p) and p[j] == "*":
            j += 1
        if j == len(p):
            return True
        return False




class Solution1: # the idea is much simpler, but Time Limit Exceeded
    def isMatch(self, s, p):
        # write your code here
        n, m = len(s), len(p)
        f = [[False]*(m+1) for i in range(n+1)]
        f[0][0] = True
            
        for i in range(n+1):
            for j in range(1, m+1):
                if p[j-1] == '?' or (i > 0 and s[i-1] == p[j-1]):
                    f[i][j] = f[i-1][j-1]
                elif p[j-1] == '*':
                    f[i][j] = ((i > 0 and f[i-1][j]) or f[i][j-1])
        return f[n][m]

def main():
    s = Solution()
    print s.isMatch("abcde", "*?*?*?*?")

if __name__ == "__main__":
    main()
