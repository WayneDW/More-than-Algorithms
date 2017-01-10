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

/*Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.*/


class NumArray {
public:
    NumArray(vector<int> &nums) {
        dp.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            dp.push_back(dp.back() + nums[i]);
        }
    }

    int sumRange(int i, int j) {
        return dp[j + 1] - dp[i];
    }
private:
    vector<int> dp;
};



int main() {
    Solution s;
    Examples eg;
}
