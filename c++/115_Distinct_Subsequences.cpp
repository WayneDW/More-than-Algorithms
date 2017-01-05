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

/*Given a string S and a string T, count the number of distinct subsequences of T in S.
A subsequence of a string is a new string which is formed from the original string by 
deleting some (can be none) of the characters without disturbing the relative positions 
of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.

Use dynamic programming to solve this question

dp[i][j] represents the number with T[:i] and S[:j], here real values are T:0~i-1, S:0~j-1

       S[:j]
      0 r a b b b i t
    0 1 1 1 1 1 1 1 1     one way: deleting all of them
    r 0 1 1 1 1 1 1 1
    a 0 0 1 1 1 1 1 1
T[i]b 0 0 0 1 2 3 . .
    b 0 0 . . . . . .
    i 0 0
    t 0 0
*/



class Solution {
public:
    int numDistinct(string s, string t) {
        int m = t.size(), n = s.size();
        int dp[m + 1][n + 1] = {0};
        for (int i = 0; i <= n; i++) dp[0][i] = 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (t[i-1] == s[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                else dp[i][j] = dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};


int main() {
    Solution s;
    Examples eg;
}
