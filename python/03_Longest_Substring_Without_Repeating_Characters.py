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
