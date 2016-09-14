#!/usr/bin/python

class Solution(object):
    def exist(self, board, word):    	
    	m, n = len(board), len(board[0])
    	if not m or not n:
    		return False
    	track = [[0] * n for i in range(m)]
    	for i in range(m):
    		for j in range(n):
    			if self.dfs(board, i, j, track, word, 0, m, n):
    				return True
    	return False

    def dfs(self, board, i, j, track, word, index, m, n):
    	if index == len(word):
    		return True
    	if i < 0 or i >= m or j < 0 or j >= n or board[i][j] != word[index] or track[i][j]:
    		return False
    	track[i][j] = 1
    	# important, if only one of 4 directions works, then match
    	if self.dfs(board, i + 1, j, track, word, index + 1, m, n): return 1
    	if self.dfs(board, i - 1, j, track, word, index + 1, m, n): return 1
    	if self.dfs(board, i, j + 1, track, word, index + 1, m, n): return 1
    	if self.dfs(board, i, j - 1, track, word, index + 1, m, n): return 1
    	track[i][j] = 0 # important, recover tag when we haven't tried that route.
    	return False


def main():
    s = Solution()
    dat = ["CAA",
           "AAA",
           "BCD"]
    print s.exist(dat, "AAB")


if __name__ == "__main__":
    main()
