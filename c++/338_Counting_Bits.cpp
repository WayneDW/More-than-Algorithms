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

/*
    dp[i] represents the occurence times of 1 of number i
             00000 0      0    dp[0] = 0
             00001 1      1    dp[0] + 1
             00010 2      1    dp[0] + 1
             00011 3      2    dp[1] + 1
             00100 4      2    dp[0] + 1
             00101 5      2    dp[1] + 1
             00110 6      2    dp[2] + 1
             00111 7      3    dp[3] + 1
             01000 8      1    dp[0] + 1
             01001 9      2    dp[1] + 1
             01010 10     2    dp[2] + 1
             01011 11     3    dp[3] + 1
             01100 12     2    dp[4] + 1
             01101 13     3    dp[5] + 1
             01110 14     3    dp[6] + 1
             01111 15     4    dp[7] + 1
             10000 16     1    dp[0] + 1
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        int dp[5] = {0};
        dp[0] = 0;
        for (int i = 1; i <= num; i *= 2) {
            for (int j = 0; j < i && j + i < num; j++) {
                dp[i+j] = dp[j] + 1;
            }
        }
        return dp;
    }
};


int main() {
	Solution s;
    Examples eg;
}
