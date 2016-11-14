#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid) {
    	int m = obstacleGrid.size();
    	int n = obstacleGrid[0].size();
    	int dp[m][n] = {{0}};
    	dp[0][0] = 1 - obstacleGrid[0][0];
    	for (int i = 1; i < m; i++)
    		dp[i][0] = dp[i - 1][0] * (1 - obstacleGrid[i][0]);
    	for (int i = 1; i < n; i++)
    		dp[0][i] = dp[0][i - 1] * (1 - obstacleGrid[0][i]);
    	for (int i = 0; i < m - 1; i++) {
    		for (int j = 0; j < n - 1; j++) {
    			dp[i + 1][j + 1] = dp[i + 1][j] * (1 - obstacleGrid[i + 1][j]) + dp[i][j + 1] * (1 - obstacleGrid[i][j + 1]);
    		}
    	}
    	return dp[m - 1][n - 1] * (1 - obstacleGrid[m - 1][n - 1]);
    }
};

int main() {
	int dat[] = {0, 0};
	vector<vector<int> > vec;
	vector<int> tmp(dat, dat + 2);
	vec.push_back(tmp);
	Solution s;
	cout << s.uniquePathsWithObstacles(vec) << endl;

}