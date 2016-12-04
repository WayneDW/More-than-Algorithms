#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int n = nums.size();
        if (n == 0) return res;
        if (n == 1) {
            string s = to_string(nums[0]);
            res.push_back(s);
        }
        else {
            vector<int> vec;
            string line;
            for (int i = 0; i < n - 1; i++) {
                if (vec.size() == 0 || nums[i-1] + 1 == nums[i]) vec.push_back(nums[i]);
                if (nums[i] + 1 != nums[i+1]){
                    if (vec.size() == 1) line = to_string(vec[0]);
                    else line = to_string(vec[0]) + "->" + to_string(vec.back());
                    res.push_back(line);
                    vec.clear();
                }
            }
            if (vec.size() > 0) {
                line = to_string(vec[0]) + "->" + to_string(nums.back());
                res.push_back(line);
            }
            else {
                line = to_string(nums.back());
                res.push_back(line);
            }

        }
        return res;
    }
};

int main() {
    Solution s;
    Examples eg;
    // vector<int> vec = {0,1,2,4,5,7};
    vector<int> vec = {1, 2,3};
    printVector(s.summaryRanges(vec));
}
