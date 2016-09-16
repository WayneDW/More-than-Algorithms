#!/usr/bin/python


# 2 successive values differ in 1 bit
class Solution:
    def grayCode(self, n):
        if n < 0:
        	return []
        res = [0]
        shift = 1
        for i in range(n):
        	for j in range(len(res) - 1, -1, -1):
        		res.append(res[j] + shift)
        	shift = shift << 1
        return res

def main():
    s = Solution()
    print s.grayCode(3)

if __name__ == "__main__":
    main()
