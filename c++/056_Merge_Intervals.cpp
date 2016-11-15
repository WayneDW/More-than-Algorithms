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
	static bool cmp(Interval a, Interval b) { // mistake without static
		return a.start < b.start;
	}
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n <= 1) return intervals;
        vector<Interval> res;
        sort(intervals.begin(), intervals.end(), cmp);
        res.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
        	if (res.back().end < intervals[i].start) {
        		// two ways of struct initialization
        		//Interval s = {intervals[i].start, intervals[i].end};
        		//Interval s = Interval(intervals[i].start, intervals[i].end);
        		//res.push_back(s);
        		res.push_back(intervals[i]);
        	}
        	else
        		res.back().end = max(intervals[i].end, res.back().end);
        }
        return res;
    }
};



int main() {
	Solution s;
}