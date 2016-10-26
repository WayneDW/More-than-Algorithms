#!/usr/bin/python
import unittest


class Solution(object):
    def isNumber(self, s):
        numList = ['.', 'e']
        for i in range(10):
            numList.append(str(i))
        n = len(s)
        # get rid of spaces on both sides
        l, r = 0, 0
        for i in range(len(s)):
            if s[i] != " ":
                l = i
                break
        for i in range(len(s), -1, -1):
            if s[n - i - 1] != " ":
                r = n - 1 - i
        s = s[l : r + 1]
        if s[0] == '-' or s[0] == '+': s = s[1:]
        if len(s) == 0 or s == '.' or s[0] == 'e' or s[-1] == 'e': return False
        if s[:2] == '.e' or s[-2:] == 'e.' or s[-2:] == 'e+' or s[-2:] == 'e-': return False

        tag = 0 # count the number of .
        tage = 0 # cnt e
        for i in range(len(s)):
            if s[i] == '.': tag += 1
            elif s[i] == 'e':
                tage += 1
            elif i > 0 and (s[i] == '+' or s[i] == '-') and s[i - 1] == "e":
                continue
            elif s[i] not in numList: return False
        if tag > 1: return False
        if tage > 1: return False
        parts = s.split('e')
        if len(parts) == 2:
            for i in range(len(parts[1])):
                if parts[1][i] == '.':
                    return False
        return True



def main():
    s = Solution()
    print s.isNumber("32.e-80123")


if __name__ == "__main__":
    main()
