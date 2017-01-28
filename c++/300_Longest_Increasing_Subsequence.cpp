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

/*Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that 
there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) { // o(n^2) dynamic programming
        int maxLen = 0;
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1); // number of LIS ends at i
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
            }
        }
        for (auto v: dp) maxLen = max(maxLen, v);
        return maxLen;
    }

    //     // Binary search (note boundaries in the caller)
    // int CeilIndex(std::vector<int> &v, int l, int r, int key) {
    //     while (r-l > 1) {
    //     int m = l + (r-l)/2;
    //     if (v[m] >= key)
    //         r = m;
    //     else
    //         l = m;
    //     }
     
    //     return r;
    // }
     
    // int LongestIncreasingSubsequenceLength(std::vector<int> &v) {
    //     if (v.size() == 0)
    //         return 0;
     
    //     std::vector<int> tail(v.size(), 0);
    //     int length = 1; // always points empty slot in tail
     
    //     tail[0] = v[0];
    //     for (size_t i = 1; i < v.size(); i++) {
    //         if (v[i] < tail[0])
    //             // new smallest value
    //             tail[0] = v[i];
    //         else if (v[i] > tail[length-1])
    //             // v[i] extends largest subsequence
    //             tail[length++] = v[i];
    //         else
    //             // v[i] will become end candidate of an existing subsequence or
    //             // Throw away larger elements in all LIS, to make room for upcoming greater elements than v[i]
    //             // (and also, v[i] would have already appeared in one of LIS, identify the location and replace it)
    //             tail[CeilIndex(tail, -1, length-1, v[i])] = v[i];
    //         print(tail);
    //     }
     
    //     return length;
    // }
    int lengthOfLIS_v2(const vector<int>& nums) { // v2 is still hard to understand
        if (nums.empty())
          return 0;
        vector<int> tails;
        tails.push_back(nums.front());

        for (auto n : nums) {
            auto iter = lower_bound(tails.begin(), tails.end(), n); // basically a binary search
            if (iter == tails.end())
                tails.push_back(n);
            else if (n < *iter)
                *iter = n;
        }
        return tails.size();
    }
    // // https://discuss.leetcode.com/topic/38503/short-c-stl-based-solution-o-n-log-n-time-o-1-space-with-explanation/2
    int lengthOfLIS_v3(vector<int>& nums) { // better see v2 to understand v3
        if (nums.size() == 0)
            return nums.size();

        vector<int>::iterator m = nums.begin();  // m will mark the virtual "S.end()".
        for (int& val : nums) {
            auto it = lower_bound(nums.begin(), m, val);
            *it = val;
            if (it == m)
                m++;
        }
        
        return m - nums.begin();
    }
};
 


int main() {
    Solution s;
    Examples eg;
    vector<int> nums = {10, 9, 2, 5, 6, 3, 7, 101, 18};
    cout << s.lengthOfLIS(nums) << endl;
}
