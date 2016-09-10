#!/usr/bin/python

class Solution(object):
    def generateMatrix(self, n):
        left, top = [0] * 2
        right, down = [n - 1] * 2
        direction = 0
        res = [[0] * n for i in range(n)]
        number = 1
        while 1:
        	if direction == 0:
        		for i in range(left, right + 1):
        			res[top][i] = number
        			number += 1       			
        		top += 1
        	if direction == 1:
        		for i in range(top, down + 1):
        			res[i][right] = number
        			number += 1
        		right -= 1
        	if direction == 2:
        		for i in range(right, left - 1, -1):
        			res[down][i] = number
        			number += 1
        		down -= 1
        		
        	if direction == 3:
        		for i in range(down, top - 1, -1):
        			res[i][left] = number
        			number += 1
        		left += 1
        	if number == n ** 2 + 1:
        		break
        	direction = (direction + 1) % 4
        return res
        	





def main():
    s = Solution()
    print s.generateMatrix(3)

if __name__ == "__main__":
    main()