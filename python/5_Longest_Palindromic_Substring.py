class Solution(object):
    def longestPalindrome(self, s):
        substring = ''
        for i in xrange(len(s)):
            subS = self.ifPalin(s, i, i)
            if len(subS) > len(substring):
                substring = subS
            # for even case
            subS = self.ifPalin(s, i, i + 1)
            if len(subS) > len(substring):
                substring = subS
            
        return substring

    def ifPalin(self, s, start, end):
        while start >= 0 and end < len(s) and s[start] == s[end]:
            start -= 1
            end += 1

        return s[start + 1:end]