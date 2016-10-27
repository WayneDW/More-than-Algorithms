#!/usr/bin/python
import unittest



class Solution(object):
    def fullJustify(self, words, maxWidth):
        if maxWidth == 0: return [""]
        res = []
        stk = []
        line = ""
        totalLen = 0
        for i, word in enumerate(words):
            wlen = len(word)
            if i > 0 and totalLen + wlen + len(stk) > maxWidth:
                if len(stk) > 1:
                    lenSpaces = maxWidth - totalLen # number of spaces left
                    if len(stk) > 2:
                        lenavg = lenSpaces / (len(stk) - 1)
                        lenArr = [0] * (len(stk) - 1)
                        firstNum = lenSpaces - lenavg * (len(stk) - 1)
                        for i in range(firstNum):
                            line += stk[i] + " " * (lenavg + 1)
                        for i in range(firstNum, len(stk) - 1):
                            line += stk[i] + " " * lenavg
                        line += stk[-1]
                    else:
                        line = stk[0] + " " * lenSpaces + stk[1]
                else:
                    line = stk[0] + " " * (maxWidth - len(stk[0]))
                res.append(line)
                line = ""
                totalLen = 0
                stk = []
            totalLen += wlen
            stk.append(word)
        # deal with the last word
        if len(stk) == 1:
            line = stk[0] + " " * (maxWidth - len(stk[0]))
        else:
            for key in stk:
                line += key + " "
            line += " " * (maxWidth - len(line))
        res.append(line)
        return res

def main():
    s = Solution()
    #words = ["This", "is", "an", "example", "of", "text", "justification."]
    words = ["Don't","go","around","saying","the","world","owes","you","a","living;","the","world","owes","you","nothing;","it","was","here","first."]
    maxWidth = 30
    print s.fullJustify(words, maxWidth)


if __name__ == "__main__":
    main()
