#!/usr/bin/python
import sys

class Solution(object):
    def __init__(self, s):
        self.string = s
    def longestPalindrome(self, s):
        substring = ''
        for i in xrange(len(s)):
            subS = self.ifPalin(s, i, i)
            if len(subS) > len(substring):
                substring = subS
            subS = self.ifPalin(s, i, i + 1)
            if len(subS) > len(substring):
                substring = subS
            print i, i + 1, substring
        return substring

    def ifPalin(self, s, start, end):
        while start >= 0 and end < len(s) and s[start] == s[end]:
            start -= 1
            end += 1
        # return start + 1 since the last check of substract -= 1 
        # has been used to start, however "abb"[1:2] is "b" 
        return s[start + 1:end]
def main():
    s = "abb"
    print s[1:2]
    sol = Solution(s)
    print sol.longestPalindrome(s)
    

if __name__ == "__main__":
    main()
