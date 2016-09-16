#!/usr/bin/python

'''
class Solution(object):
    def search(self, nums, target):
    	start = self.findPivot(nums, 0)
    	nums = nums[start + 1:] + nums[:start + 1]
    	pos = self.binSearch(nums, 0, target)
    	return pos

    def findPivot(self, num, start):
    	n = len(num)
    	if n == 2 and num[0] <= num[1]:
    		return -1
    	if n <= 2:
    		return start
    	mid = (n - 1) / 2 # 8 : 3, 9 : 4
    	if num[mid] > num[n - 1]:
    		start = self.findPivot(num[mid:], start + mid)
    	else:
    		start = self.findPivot(num[:mid + 1], start)
    	return start
    def binSearch(self, num, start, target):
    	n = len(num)
    	mid = (n - 1) / 2
    	if n == 1 and num[0] != target:
    		return False
    	if num[mid] == target:
    		return mid + start
    	elif num[0] > target or num[n - 1] < target:
    		return False
    	elif num[mid] < target:
    		pos = self.binSearch(num[mid + 1:], start + mid + 1, target)
    	else:
    		pos = self.binSearch(num[:mid], start, target)
    	return pos
'''

# a better way in iteration rather than recursion
class Solution(object):
	def search(self, nums, target):
		left, right = 0, len(nums) - 1
		while left <= right:
			mid = left + (right - left) / 2
			if nums[mid] == target:
				return True
			elif nums[mid] > nums[right]:
				if target < nums[mid] and target >= nums[left]:
					right = mid - 1
				else:
					left = mid + 1
			elif nums[mid] < nums[right]:
				if target > nums[mid] and target <= nums[right]:
					left = mid + 1
				else:
					right = mid - 1
			else:
				right -= 1
		return False




def main():
    s = Solution()
    '''
    print s.findPivot([4,4,5,5,7,1,2,3,3], 0)
    print "..................................................."
    print s.findPivot([4,4,5,5,7,1,2,3], 0)
    print "..................................................."
    print s.findPivot([1,2,3,4,5,6,7], 0)
    print "..................................................."
    print s.findPivot([1,2,3,4,5,6,7,8], 0)
    '''
    print s.search([1,1], 0)

if __name__ == "__main__":
    main()
