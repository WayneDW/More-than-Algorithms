'''
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
'''

class Solution:
    # python may run out of time
    def convert(self, s, numRows):
        sub = ""
        if numRows < 2 or len(s) <= numRows:
            return s
        for i in xrange(numRows):
            tmp = 0
            while tmp + i < len(s):
                if i > 0 and i < numRows - 1 and tmp > i:
                    sub += s[tmp - i]
                sub += s[tmp + i]
                tmp += 2 * (numRows - 1)

            if tmp + i >= len(s) and tmp - i < len(s) and i < numRows - 1:
                sub += s[tmp - i]
        return sub
