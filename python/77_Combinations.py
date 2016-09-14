#!/usr/bin/python


class Solution1(object):
	def combine(self, n, k):
		def backTracking(start, res):
			if len(res) == k:
				result.append(res)
			for item in range(start, n + 1):
				backTracking(item + 1, res + [item])
		result = []
		backTracking(1, [])
		return result    

class Solution(object):
	def combine(self, n, k):
		result = []
		self.backTracking(1, n, k, 0, [], result)
		return result 
	def backTracking(self, start, n, k, p, res, result):
		if p == k:
			result.append(res)
			return
		for item in range(start, n + 1):
			''' # this method fails with empty result
			res.append(item)
			self.backTracking(item + 1, n, k, p + 1, res, result)
			res.pop()
			'''
			self.backTracking(item + 1, n, k, p + 1, res + [item], result)
			






def main():
    s = Solution()
    print s.combine(4, 2)



if __name__ == "__main__":
    main()
