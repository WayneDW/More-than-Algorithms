#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp[i]: maximum value from left to i
        int n = nums.size();
        if (n == 0) return -1;
        int dp[n] = {0};
        dp[0] = nums[0];
        int maxN = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            maxN = max(maxN, dp[i]);
        }
        return maxN;
    }
};
