#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1)
            return 1;
        int dp[m + 1][n + 1] = {{0}};
        for (int i = 0; i < m + 1; i++)
            dp[i][1] = 1;
        for (int i = 1; i < n + 1; i++)
            dp[1][i] = 1;
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
            }
        }
        return dp[m][n];
    }
};


int main() {
    Solution s;
    cout << s.uniquePaths(10, 10) << endl;
}