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

/*Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.*/



/* 
    dp(i+1,j+1): the size that gives us the maximum area at (i, j), area = size^size
    the first row and column have the same for value for dp and matrix
    in the rest part, dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
                       r0: 1 1 1 1 1
                         ___________
    1 0 1 1 1       c0 1 | 1 0 1 1 1
    0 1 1 1 1   -->    1 | 0 1 1 2 2
    0 0 1 1 1          1 | 0 0 1 2 3 */

class Solution {
public:
    int maximalSquare(vector<vector<char> >& matrix) {
        int m = matrix.size();
        if (!m) return 0;
        int n = matrix[0].size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));
        int size = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    if (i == 0 || j == 0) dp[i+1][j+1] = matrix[i][j] - '0';
                    else dp[i+1][j+1] = min(dp[i][j], min(dp[i][j+1], dp[i+1][j])) + 1;
                    size = max(size, dp[i+1][j+1]);
                }
            }
        }
        return size * size;
    }
};



int main() {
    Solution s;
    Examples eg;
}
