#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int dp[n+1] = {0};
        dp[1] = nums[0];
        for (int i = 2; i < n+1; i++) {
            dp[i] = max(dp[i-1], nums[i-1] + dp[i-2]);
        }
        return dp[n];
    }
};


int main() {
	Solution s;
    Examples eg;
}
