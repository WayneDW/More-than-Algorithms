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

/*After robbing those houses on that street, the thief has found himself a new place for his 
thievery so that he will not get too much attention. This time, all houses at this place are 
arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, 
the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine
 the maximum amount of money you can rob tonight without alerting the police.*/


/* dp1[n] represents the maximum of money we can rob from 0 to i
   dp2[n] represents the maximum of money we can rob from 1 to i  i >= 1
   if dp1[n] > dp2[n], this means 0 is robbed, check if n-1 is also robbed
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int dp1[n] = {0}, dp2[n] = {0};
        
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        dp1[0] = nums[0], dp1[1] = max(nums[0], nums[1]);
        dp2[1] = nums[1];
        for (int i = 2; i < n; i++) {
            dp1[i] = max(dp1[i-2] + nums[i], dp1[i-1]);
            dp2[i] = max(dp2[i-2] + nums[i], dp2[i-1]);
        }

        if (dp1[n-1] > dp1[n-2] && dp1[n-1] > dp2[n-1]) return max(dp1[n-2], dp2[n-1]); // n - 1 and 0 is both robbed
        return dp1[n-1];
    }
};

int main() {
    Solution s;
    Examples eg;
    vector<int> nums = {};
    cout << s.rob(nums) << endl;
}
