#!/usr/bin/python
import unittest


class Solution(object):
    def insert(self, intervals, newInterval):
        if len(intervals) == 0:
            return [newInterval]
        for i in range(len(intervals)):
            if intervals[i].start > newInterval.start:
                loc = i # binary search would be better, just skip it
                break
        if intervals[-1].start <= newInterval.start: loc = i + 1
        res = [newInterval]
        for i in range(loc, 0,  -1):
            if intervals[i - 1].end >= res[0].start:
                res[0].start = intervals[i - 1].start
                res[0].end = max(res[0].end, intervals[i - 1].end)
            else:
                res.insert(0, intervals[i - 1])

        for i in range(loc, len(intervals)):
            if res[-1].end >= intervals[i].start:
                res[-1].end = max(intervals[i].end, res[-1].end)
            else:
                res.append(intervals[i])
        return res
                


        

def main():
    s = Solution()
    s.insert()


if __name__ == "__main__":
    main()
