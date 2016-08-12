'''
Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
'''

class Solution(object):
    # get longest substring
    def lengthOfLongestSubstring(self, s):
        last = -1
        maximum = 0
        n = len(s)
        sets = {}
        for i in range(n):
            # last < sets[] is to get rid of cases as "abba"
            if s[i] in sets and last < sets[s[i]]:
                last = sets[s[i]]
            sets[s[i]] = i
            maximum = max(i - last, maximum)
        return maximum
