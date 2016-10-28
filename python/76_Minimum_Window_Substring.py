#!/usr/bin/python
import unittest
import collections

'''
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".
'''

# feasible, but very inefficient

class Solution(object):
    def minWindow(self, s, t):
        if s == t: return t
        dt = {}
        for i in range(len(t)):
            dt.setdefault(t[i], 0)
            dt[t[i]] += 1 # create a dict to count the number of words
        arr1 = []
        arr2 = []
        for num, i in enumerate(range(len(s))):
            if s[i] in dt:
                arr1.append(s[i])
                arr2.append(num) # record the word and location
        i, j, total = 0, 0, 10 ** 10
        dt2 = {} # comparision dict
        res = "" # final result
        tag = 1
        while i < len(arr1) or j < len(arr1):
            if tag and j < len(arr1) and not self.check(dt, dt2): # if dict not match, update dt2
                dt2.setdefault(arr1[j], 0)
                dt2[arr1[j]] += 1
                if j == len(arr1) -1: tag = 0 # avoid repeatly updating dt2
            if self.check(dt, dt2) and i < len(arr1): 
                if arr2[j] - arr2[i] < total:
                    res = s[arr2[i]:arr2[j] + 1]
                total = min(total, arr2[j] - arr2[i] + 1)
                dt2[arr1[i]] -= 1
                if dt2[arr1[i]] == 0: del dt2[arr1[i]]
                i += 1
            elif j >= len(arr1) - 1:
                break
            if j < len(arr1) - 1 and not (self.check(dt, dt2) and i < len(arr1)):
                j += 1

        return res
    def check(self, a, b):
        for i in a:
            if i not in b: return False
            if a[i] > b[i]: return False
        return True

class Solution2(object):
    def minWindow(self, s, t):
        need, missing = collections.Counter(t), len(t)
        i = I = J = 0
        for j, c in enumerate(s, 1):
            missing -= need[c] > 0
            need[c] -= 1
            print c, need
            if not missing:
                while i < j and need[s[i]] < 0:
                    need[s[i]] += 1
                    i += 1
                if not J or j - i <= J - I:
                    I, J = i, j
        return s[I:J]

def main():
    s = Solution()
    #assert s.minWindow("adobecodebanc", "abc") == "banc"
    #assert s.minWindow("bba", "ab") == "ba"
    #assert s.minWindow("cabwefgewcwaefgcf", "cae") == "cwae"
    print s.minWindow("aabcdb", "bd") 
    #assert s.minWindow("cabefgecdaecf", "aec") == "aec"
    #assert s.minWindow("acbba", "aab") == "acbba"




if __name__ == "__main__":
    main()
