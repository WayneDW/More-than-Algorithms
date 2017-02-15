#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

/*Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, 
the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).*/


class Solution_dfs_bit_mask {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return res;
        m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> path(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            dfs(matrix, path, i, 0, INT_MIN, 1);
            dfs(matrix, path, i, n - 1, INT_MIN, 2);
        }
        for (int i = 0; i < n; i++) {
            dfs(matrix, path, 0, i, INT_MIN, 1);
            dfs(matrix, path, m - 1, i, INT_MIN, 2);
        }
        return res;
    }

    void dfs(vector<vector<int>> &matrix, vector<vector<int>> &path, int i, int j, int h, int preVal) {
        if (i < 0 || j < 0 || i >= m || j >= n || (path[i][j] & preVal) == preVal || matrix[i][j] < h) return;
        path[i][j] |= preVal;
        if (path[i][j] == 3) res.push_back(make_pair(i, j)); // bit mask, 1, 1
        dfs(matrix, path, i + 1, j, matrix[i][j], path[i][j]);
        dfs(matrix, path, i - 1, j, matrix[i][j], path[i][j]);
        dfs(matrix, path, i, j + 1, matrix[i][j], path[i][j]);
        dfs(matrix, path, i, j - 1, matrix[i][j], path[i][j]);
    }
private:
    int m, n;
    vector<pair<int, int>> res;
};


int main() {
    Solution s;
    Examples eg;
    // vector<vector<int>> matrix = {{1,2,2,3,5}, 
    //                               {3,2,3,4,4}, 
    //                               {2,4,5,3,1}, 
    //                               {6,7,1,4,5}, 
    //                               {5,1,1,2,4}};
    vector<vector<int>> matrix = {{10, 10, 10},
                                  {10,  1, 10},
                                  {10, 10, 10}}; 

    print(s.pacificAtlantic(matrix));
}
