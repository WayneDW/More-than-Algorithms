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

/*Given a non-empty array containing only positive integers, find if the array can be 
partitioned into two subsets such that the sum of elements in both subsets is equal.

Note:
Each of the array element will not exceed 100.
The array size will not exceed 200.
Example 1:

Input: [1, 5, 11, 5]

Output: true

Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: [1, 2, 3, 5]

Output: false

Explanation: The array cannot be partitioned into equal sum subsets.*/

class Solution { 
public:
    bool canPartition(vector<int>& nums) { // TLE version 
        if (nums.size() == 0) return false;
        int sum = 0;
        for (auto v: nums) sum += v;
        return sum % 2 == 0 && dfs(nums, 0, 0, sum / 2);
    }

    bool dfs(vector<int> nums, int cur, int pos, int target) {
        if (pos >= nums.size()) return false;
        if (cur >= target) {
            return cur == target;
        }
        else {
            bool tag;
            tag = dfs(nums, cur, pos + 1, target) || dfs(nums, cur + nums[pos], pos + 1, target);
            if (tag) return true;
            else return false;
        }
    }
     bool canPartition(vector<int>& nums) { // dp version
        int sum = 0;
        for (auto n: nums) sum += n;
        if (sum & 1) return false;
        int n = sum >> 1;
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (auto i: nums) {
            for (int j = n; j >= i; j--) {
                dp[j] = dp[j] || dp[j - i];
            }
        }
        return dp[n];
    }
    
    bool canPartition(vector<int> nums) { // bitset version, concise
        int sum = 0;
        for (auto i: nums) sum += i;
        bitset<5001> bits(1); // initialize with location 0 as 1 and other places as 0
        for (auto i: nums) {
            bits |= bits << i;
        }
        int n = nums.size();
        return !(sum & 1) && bits[sum / 2];
    }
};


int main() {
    Solution s;
    Examples eg;
    vector<int> nums = {1, 5, 10, 4};
    cout << s.canPartition(nums) << endl;
}
