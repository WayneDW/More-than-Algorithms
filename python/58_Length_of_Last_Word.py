#!/usr/bin/python
import sys
import os


class Solution(object):
    def lengthOfLastWord(self, s):
        n = len(s)
        length, tag = 0, 1
        for i in range(n - 1, -1, -1):
            if s[i] == ' ' and tag:
                continue
            elif s[i] == ' ' and not tag:
            	break
            if s[i] != ' ':
                tag = 0
            length += 1
        
        return length
        
        


def main():
    s = Solution()
    print s.lengthOfLastWord("abc deffa  ")

if __name__ == "__main__":
    main()
