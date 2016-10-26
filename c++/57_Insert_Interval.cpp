#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        res.push_back(newInterval);

        int n = intervals.size();
        if (n == 0) return res;
        int loc = n;
        for(int i = 0; i < n; i++) {
            cout << i << endl;
            if (intervals[i].start > newInterval.start) {
                loc = i;
                break;
            }
        }

        for (int i = loc; i > 0; i--) {
            if (res[0].start <= intervals[i - 1].end) {
                res[0].start = intervals[i - 1].start;
                res[0].end = max(intervals[i - 1].end, res[0].end);
            }
            else
                res.insert(res.begin(), intervals[i - 1]);
        }
        for (int i = loc; i < n; i++) {
            if (res.back().end >= intervals[i].start)
                res.back().end = max(res.back().end, intervals[i].end);
            else
                res.push_back(intervals[i]);
        }

        return res;
    }
};



int main() {
    Solution s;
}