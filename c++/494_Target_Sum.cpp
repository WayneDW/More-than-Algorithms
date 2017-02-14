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
#include <functional>
#include <numeric>
#include "000_basic.cpp"

using namespace std;

/*You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 
symbols + and -. For each integer, you should choose one from + and - as its new symbol.

Find out how many ways to assign symbols to make sum of integers equal to target S.

Example 1:
Input: nums is [1, 1, 1, 1, 1], S is 3. 
Output: 5
Explanation: 

-1+1+1+1+1 = 3
+1-1+1+1+1 = 3
+1+1-1+1+1 = 3
+1+1+1-1+1 = 3
+1+1+1+1-1 = 3

There are 5 ways to assign symbols to make the sum of nums be target 3.*/

class Solution_slow {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0;
        dfs(nums, 0, sum, 0, S, 1);
        dfs(nums, 0, sum, 0, S, -1);
        return sum;
    }

    void dfs(vector<int>& nums, int loc, int& sum, int cur, int S, int sign) {
        cur += nums[loc] * sign; // take outside, rather than in the else loop
        if (loc == nums.size() - 1) {
            if (cur == S) sum++;
            else return;
        }
        else {
            dfs(nums, loc + 1, sum, cur, S, 1);
            dfs(nums, loc + 1, sum, cur, S, -1);
        }
    }
};

/* when i = 0, 4 + 1 = 6 - 1
   when i = 1, 3, 7 using 2 additions or 2 subtractions cant get 5, or 5 + 1 - 1 or 5 - 1 + 1
0 0 0 0 1 0 1 0 0 0 0 
0 0 0 1 0 2 0 1 0 0 0 
0 0 1 0 3 0 3 0 1 0 0 
0 1 0 4 0 6 0 4 0 1 0 
1 0 5 0 10 0 10 0 5 0 1 */
class Solution_good { // https://discuss.leetcode.com/topic/76264/short-java-dp-solution-with-explanation
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (S > sum || S < -sum) return 0;
        vector<int> dp(2 * sum + 1, 0);
        dp[sum] = 1;
        for (int i = 0; i < nums.size(); i++) {
            vector<int> next(2 * sum + 1, 0);
            for (int k = 0; k < 2 * sum + 1; k++) {
                if (dp[k] != 0) {
                    next[k + nums[i]] += dp[k];
                    next[k - nums[i]] += dp[k];
                }
            }
            dp = next;
        }
        return dp[sum + S];
    }
};


class Solution { // https://leetcode.com/problems/target-sum/?tab=Solutions
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < s) return 0;
        return (sum + s) & 1 ? 0: subsetSum(nums, (sum + s) >> 1);
    }

    int subsetSum(vector<int>& nums, int s) {
        vector<int> dp(s + 1, 0);
        dp[0] = 1;
        for (auto n: nums) {
            for (int i = s; i >= n; i--) {
                dp[i] += dp[i - n]; // for the first N numbers in nums, dp[i] represent the number of combinations that can lead to total i
            }
            print(dp);
        }
        return dp[s];
    }
};

int main() {
    Solution s;
    Examples eg;
    vector<int> nums = {1, 2, 3, 4, 5};
    cout << s.findTargetSumWays(nums, 7) << endl;
}
