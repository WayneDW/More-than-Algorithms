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

/*Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by 
its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and 
(row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12*/

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int m = matrix.size();
        for (int i = 0; i < m; i++) {
            vector<int> tmp;
            dp.push_back(tmp);
            dp[i].push_back(0);
            for (int j = 0; j < matrix[0].size(); j++) {
                dp[i].push_back(dp[i].back() + matrix[i][j]);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            sum += dp[i][col2 + 1] - dp[i][col1];
        }        
        return sum;
    }
private:
    vector<vector<int> > dp;
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);


int main() {
    Solution s;
    Examples eg;
}
