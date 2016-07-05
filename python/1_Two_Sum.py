class Solution(object):
    def twoSum(self, nums, target):
        d = {}
        # set key to default if the key is not in dict
        for num, dat in enumerate(nums):
            d.setdefault(dat,[]).append(num)

        for num in d:
            if target - num in nums and target - num == num:
                return d[num]
            elif target - num in nums and target - num != num:
                return sorted([d[num][0], d[target - num][0]])
        


