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

/*Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or 
move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

nums = [
  [9,9,4],
  [6,6,8],
  [2,1,1]
]
Return 4
The longest increasing path is [1, 2, 6, 9].

Example 2:

nums = [
  [3,4,5],
  [3,2,6],
  [2,2,1]
]
Return 4
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.*/

class Solution_bad_memorization { // still suffer from TLE
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        if (n == 0) return 0;
        int maxLen = 0;
        vector<vector<int>> memory(m, vector<int>(n, 1));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int curMax = 1;
                dfs(matrix, i, j, 0, 1, curMax, m, n, memory);
                memory[i][j] = curMax;
                maxLen = max(maxLen, curMax);
            }
        }
        return maxLen;
    }


    void dfs(vector<vector<int>>& matrix, int i, int j, int maxV, int curLen, int& curMax, int m, int n, vector<vector<int>> &memory) {
        if (i >= 0 && i < m && j >= 0 && j < n && (curLen == 1 || matrix[i][j] > maxV)) {
            if (memory[i][j] > 1) {
                curMax = max(curMax, curLen + memory[i][j] - 1);
                return;
            }
            curMax = max(curMax, curLen);
            dfs(matrix, i + 1, j, matrix[i][j], curLen + 1, curMax, m, n, memory);
            dfs(matrix, i - 1, j, matrix[i][j], curLen + 1, curMax, m, n, memory);
            dfs(matrix, i, j + 1, matrix[i][j], curLen + 1, curMax, m, n, memory);
            dfs(matrix, i, j - 1, matrix[i][j], curLen + 1, curMax, m, n, memory);
        }
    }
};

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        int maxLen = 0;
        vector<vector<int>> memory(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int len = dfs(matrix, memory, INT_MIN, i, j, m, n);
                cout << len << endl;
                maxLen = max(len, maxLen);
            }
        }
        return maxLen;
    }

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& memory, int v, int i, int j, int m, int n) {
        if (i >= 0 && i < m && j >= 0 && j < n && matrix[i][j] > v) {
            if (memory[i][j] > 0) return memory[i][j];
            int t = dfs(matrix, memory, matrix[i][j], i + 1, j, m, n) + 1;
            int b = dfs(matrix, memory, matrix[i][j], i - 1, j, m, n) + 1;
            int l = dfs(matrix, memory, matrix[i][j], i, j - 1, m, n) + 1;
            int r = dfs(matrix, memory, matrix[i][j], i, j + 1, m, n) + 1;
            memory[i][j] = max(t, max(b, max(l, r)));
            return memory[i][j];
        }
        else return 0;
    }
};

int main() {
    Solution s;
    Examples eg;
    vector<vector<int>> matrix = {{0,1,2,3,4,5,6,7,8,9},
                                  {19,18,17,16,15,14,13,12,11,10},
                                  {20,21,22,23,24,25,26,27,28,29},
                                  {39,38,37,36,35,34,33,32,31,30},
                                  {40,41,42,43,44,45,46,47,48,49},
                                  {59,58,57,56,55,54,53,52,51,50},
                                  {60,61,62,63,64,65,66,67,68,69},
                                  {79,78,77,76,75,74,73,72,71,70},
                                  {80,81,82,83,84,85,86,87,88,89},
                                  {99,98,97,96,95,94,93,92,91,90},
                                  {100,101,102,103,104,105,106,107,108,109},
                                  {119,118,117,116,115,114,113,112,111,110},
                                  {120,121,122,123,124,125,126,127,128,129},{139,138,137,136,135,134,133,132,131,130},{0,0,0,0,0,0,0,0,0,0}};
    cout << s.longestIncreasingPath(matrix) << endl;
}
