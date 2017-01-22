#include <iostream>
#include <vector>
#include <map>
#include <set>
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

/*Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented 
by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get 
nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the 
burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note: 
(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

Example:

Given [3, 1, 5, 8]

Return 167

    nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
   coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167*/


/* since only the first and last one can seperately the left and right part perfectly, normal order DP 
doesn't work well, thus we consider iterate from the last one back to the beginning
see explanation https://discuss.leetcode.com/topic/30746/share-some-analysis-and-explanations
and code https://discuss.leetcode.com/topic/41086/c-dp-detailed-explanation
the last one is the maximum value when we iterate i from left to right: num[left-1]*num[i]*[right+1]

e.g. in the last step
        1     3     1    5      8     1
              |_____|    v      |
                 |       |      |
                 v       v      v
            dp[1][2] + 1*5*1 + dp[3][3] = 5 + 30 + 40 = 125 (this may not be optimal)

DP[left][right]: the maximum coins between nums[left][right]

len = 1    3   1   5   8
dp[i][i]   3   15  40  40

len = 2
0    0    0    0    0    0             
0    3    30   0    0    0   for example, dp[2][3] = max(dp[2][3], 3*5*8 + 3*5) = 135
0    0    15   135  0    0                                         |_________|
0    0    0    40   48   0                                              |
0    0    0    0    40   0                                              v
0    0    0    0    0    0                                num[left-1]*num[k]*num[right+1] + dp[][]*/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        int dp[n][n] = {0};
        for (int len = 1; len < n - 1; len++) {
            for (int l = 1; l < n - len; l++) {
                int r = l + len - 1;
                for (int k = l; k <= r; k++) {
                    dp[l][r] = max(dp[l][r], nums[l-1] * nums[k] * nums[r+1] + dp[l][k-1] + dp[k+1][r]);
                }
            }
        }
        nums.erase(nums.begin());
        nums.erase(nums.end() - 1);
        return dp[1][n-2];
    }
};

int main() {
    Solution s;
    Examples eg;
    vector<int> nums = {3, 1, 5, 8};
    cout << s.maxCoins(nums) << endl;
}
