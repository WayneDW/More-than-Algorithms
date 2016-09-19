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
			# this method fails with empty resultsince res changes the structure of result
			# res.append(item)
			# self.backTracking(item + 1, n, k, p + 1, res, result)
			# res.pop()
			self.backTracking(item + 1, n, k, p + 1, res + [item], result)			

class Solution2:
	def combine(self, n, k):
		import itertools
		return map(list, itertools.combinations(xrange(1, n + 1), k))

# great solution
class Solution3(object):
    def combine(self, n, k):
        if k == 1:
            return [[i] for i in range(1, n + 1)]
        if n == k:
            return [[i for i in range(1, n + 1)]]
        return [i + [n] for i in self.combine(n - 1, k - 1)] + [i for i in self.combine(n - 1, k)]		




def main():
    s = Solution()
    print s.combine(4, 2)



if __name__ == "__main__":
    main()
