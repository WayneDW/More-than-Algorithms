#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
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

/*Given an integer array with all positive numbers and no duplicates, find the number of 
possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < n; i++)  {
            dfs(nums, i, nums[i], target, res) ;
        }
        return res;
    }

    void dfs(vector<int>& nums, int idx, int cur, int target, int &res) {
        if (cur >= target) {
            if (target == cur) res++;
            return;
        }
        for (int i = 0; i < n; i++) {
            dfs(nums, i, cur + nums[i], target, res);
        }
    }
private:
    int n;
};

class Solution_dp {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int dp[target + 1] = {0};
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        for (int i = 1; i <= target; i++) {
            for (auto num: nums) {
                if (i < num) continue;
                dp[i] += dp[i - num];
            }
        }
        return dp[target];
    }
};

int main() {
    Solution s;
    Examples eg;
    vector<int> vec = {1,2,3};
    cout << s.combinationSum4(vec, 4) << endl;
}
