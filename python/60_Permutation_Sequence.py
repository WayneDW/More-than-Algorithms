#!/usr/bin/python


class Solution(object):
    def getPermutation(self, n, k):
    	factorial = 1
    	for i in range(1, n):
    		factorial *= i
    	if k > factorial * n:
    		return -1
    	k -= 1
    	sets = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    	tag, res = 0, ""
    	
        while k >= 0 and tag < n:
        	tag += 1
        	quotient = k / factorial
        	k -= quotient * factorial
        	res += str(sets[quotient])
        	sets.remove(sets[quotient])
        	if n == tag:
        		factorial = 1
        	else:
        		factorial /= (n - tag)
        return res
        

def main():
    s = Solution()
    print s.getPermutation(4, 9)

if __name__ == "__main__":
    main()