#!/usr/bin/python
import unittest

"""
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
"""

# Definition for an interval.
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution(object):
    def merge(self, intervals):
        if len(intervals) <= 1:
            return intervals
        intervals = sorted(intervals, key=lambda x:x.start) # remember
        res = [intervals[0]]
        for i in range(1, len(intervals)):
            if res[-1].end < intervals[i].start:
                res.append(intervals[i])
            else:
                res[-1].end = max(intervals[i].end, res[-1].end) # [[1,4], [2,3]]
        return res



def main():
    s = Solution()
    i1 = Interval(1, 4)
    i2 = Interval(1, 4)
    a = [i1, i2]
    print s.merge(a)


if __name__ == "__main__":
    main()
