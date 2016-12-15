#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include "func.cpp"

using namespace std;



class Solution_bad { // Very Inefficient
public:
    int minCut(string s) {
        int n = s.size();
        if (!n) return 0;
        vector<vector<int> > dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 0;
            for (int j = i + 1; j < n; j++) {
                if (!isPalin(s.substr(i, j - i + 1))) {
                    for (int k = i; k < j; k++)
                        dp[i][j] = min(dp[i][j]==0?INT_MAX:dp[i][j], 1 + dp[i][k] + dp[k+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
    bool isPalin(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
};

/* 
    dp[i]: the minimum cut from 0 to i
    For the following string 
    [ * * * * * * i * * ] when j = i, dp[i] = dp[i-1] + 1
    [ * * * * * j i * * ] when j = i - 1, dp[i] = dp[i-2] + 1
    [ * * * * j * i * * ] when j = i - 2, dp[i] = dp[i-3] + 1 = dp[j-1] + 1
    [ * * * j * * i * * ] when j = i - 3, and isPalin[i-1][j+1] is true, since s[i] == s[j] 
    dp[i-3] is like the minimum cut in [ * * * ]
    the right part is one cut to seperate [ * * * ] | [ j * * i]
    then dp[i] = dp[i-3] + 1 = dp[j-1] + 1
*/

class Solution {
public:
    int minCut(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<vector<bool> > isPalin(n, vector<bool>(n, false));
        vector<int> dp(n, INT_MAX);
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (s[i] == s[j] && (i - j <= 2 || isPalin[i-1][j+1])) {
                    isPalin[i][j] = true;
                    if (j == 0)
                        dp[i] = 0; // this means the whole substr is valid, the cut is 0
                    else
                        dp[i] = min(dp[i], 1 + dp[j-1]); // this means 
                }
            }
        }
        return dp[n-1];
    }
};

int main() {
    Solution s;
    Examples eg;
    int res = s.minCut("abbab");
    cout << res << endl;
}
