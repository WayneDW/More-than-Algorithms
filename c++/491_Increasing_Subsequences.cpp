#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

/*Given an integer array, your task is to find all the different possible increasing subsequences of the given array, 
and the length of an increasing subsequence should be at least 2 .

Example:
Input: [4, 6, 7, 7]
Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
Note:
The length of the given array will not exceed 15.
The range of integer in the given array is [-100,100].
The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.*/


class Solution_slow { // exp time complexity
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if (nums.empty()) return res;
        n = nums.size();
        vector<int> cur;
        dfs(nums, cur, 0);
        for (auto v: st) res.push_back(v);
        return res;
    }

    void dfs(vector<int> &nums, vector<int> cur, int loc) {
        if (loc > n) return;
        if (cur.size() > 1) st.insert(cur);

        dfs(nums, cur, loc + 1);
        if (cur.empty() || nums[loc] >= cur.back()) cur.push_back(nums[loc]);
        dfs(nums, cur, loc + 1);
        cur.pop_back();
    }
private:
    int n;
    vector<vector<int>> res;
    set<vector<int>> st;    
};


class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> cur;
        dfs(nums, cur, 0);
        return vector<vector<int>>(st.begin(), st.end());
    }

    void dfs(vector<int>& nums, vector<int> cur, int idx) {
        if (cur.size() > 1) st.insert(cur);

        for (int i = idx; i < nums.size(); i++) {
            if (cur.empty() || nums[i] >= cur.back()) {
                cur.push_back(nums[i]);
                dfs(nums, cur, i + 1); // rather than idx + i
                cur.pop_back();
            }
        }
    }
private:
    set<vector<int>> st;
};



int main() {
    Solution s;
    Examples eg;
    vector<int> vec = {4, 6, 7, 7};
    print(s.findSubsequences(vec));
}
