#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
    	int m = grid.size();
    	int n = grid[0].size();
    	int dp[m][n] = {{0}};
    	if (m == 1 && n == 1)
    		return grid[0][0];
    	dp[0][0] = grid[0][0];
    	for (int i = 0; i < m - 1; i++)
    		dp[i + 1][0] = dp[i][0] + grid[i + 1][0];
    	for (int j = 0; j < n - 1; j++)
    		dp[0][j + 1] = dp[0][j] + grid[0][j + 1];
    	for (int i = 0; i < m - 1; i++)
	    	for (int j = 0; j < n - 1; j++) 
	    		dp[i + 1][j + 1] = min(dp[i + 1][j], dp[i][j + 1]) + grid[i + 1][j + 1];
	    return dp[m - 1][n - 1];
    }
};


int main() {
	Solution s;


}