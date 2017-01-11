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

/*Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.*/

class Solution {
public:
    int numSquares(int n) {
        // about why to use static : https://discuss.leetcode.com/topic/23812/static-dp-c-12-ms-python-172-ms-ruby-384-ms
        // only is initialized once, but is it kind of like cheating?
        static vector<int> dp = {0}; // dp[i] represents the minimum number of square numbers that sum to i

        while (dp.size() <= n) {
            int cntNum = INT_MAX;
            int size = dp.size();
            for (int i = 1; i * i <= size; i++) {
                cntNum = min(cntNum, dp[size - i * i] + 1);
            }
            dp.push_back(cntNum);
        }
        return dp[n];
    }
};


int main() {
    Solution s;
    Examples eg;
}
