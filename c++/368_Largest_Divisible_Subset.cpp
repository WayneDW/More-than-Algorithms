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

/*Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

nums: [1,2,3]

Result: [1,2] (of course, [1,3] will also be ok)
Example 2:

nums: [1,2,4,8]

Result: [1,2,4,8]*/


/*idea: suppose [6,12] is possible solution set, then 3 or 24 can both be put into the set if it satisfies the condition
  sort the vector first, [3,6,9,2,4,8,16] -> [2,3,4,6,8,9,16]
  If we start from left to right

  [2] -> [2] -> [2,4] -> [2,4] -> [2,4,8] -> [2,4,8] -> [2,4,8,16]
         [3]    [3]      [3,6]    [3,6]      [3,6]      [3,6]      
                                             [9]        [9]

Record          4->2               8->4                 16->8
                          6->3  */


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 0), child(n, 0), res;

        int curParent, longest = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (nums[i] % nums[j] == 0 && dp[i] <= dp[j]) { // if dp[i] > dp[j], when num->8 (dp=3) has been added to [2,4,8], nums[j] = 2 (dp=1) should not be compared anymore
                    dp[i] = dp[j] + 1; // when i == j, set dp[i] = 1 and child[i] = i
                    child[i] = j; // record the child index
                }
                if (dp[i] > longest) {
                    curParent = i;
                    longest = dp[i];
                }
            }
        }

        while (longest--) {
            res.push_back(nums[curParent]);
            curParent = child[curParent];
        }
        print(child);
        sort(res.begin(), res.end()); // to avoid this step, you can actually start from back to front
        return res;
    }
};


int main() {
    Solution s;
    Examples eg;
    vector<int> nums = {3,6,9,2,4,8,16};
    print(s.largestDivisibleSubset(nums));
}
