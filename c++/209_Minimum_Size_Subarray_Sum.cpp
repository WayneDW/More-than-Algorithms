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

/*Given an array of n positive integers and a positive integer s, find the minimal length 
of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the 
time complexity is O(n log n).*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int left = 0, total = 0, len = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
            while (total >= s) {
                len = min(len, i - left + 1);
                total -= nums[left++];
            }
        }
        return all >= s? len: 0;
    }
};

int main() {
    Solution s;
    Examples eg;
    vector<int> nums = {2,3,1,2,4,3};
    cout << s.minSubArrayLen(7, nums) << endl;
}
