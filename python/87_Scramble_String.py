#!/usr/bin/python
import unittest


# https://discuss.leetcode.com/topic/42438/sharing-recursive-python-solution-with-memo-beats-99
class Solution(object):
    def isScramble(self, s, t, memo={}):
        # Check with sorted is fundamental, otherwise TLE
        if len(s) != len(t) or sorted(s) != sorted(t):
            return False
        if len(s) <= 3:
            return True
        if s == t:
            return True
        if (s, t) in memo:
            return memo[s, t]
        n = len(s)
        for i in range(1, n):
            a = self.isScramble(s[:i], t[:i], memo) and self.isScramble(s[i:], t[i:], memo)
            if not a:
                b = self.isScramble(s[:i], t[-i:], memo) and self.isScramble(s[i:], t[:-i], memo)
            if a or b:
                memo[s, t] = True
                return True
        memo[s, t] = False
        return False



def main():
    s = Solution()
    print s.isScramble("rgtae", "great")


if __name__ == "__main__":
    main()
