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

// add 1 when we met with 1, then use DFS to search all the adjacent points and set as 0
class Solution {
public:
    int numIslands(vector<vector<char> >& grid) {
        if (grid.size() == 0) return 0;
        int res = 0 ;
        int M = grid.size(), N = grid[0].size();
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == '1') {
                    res += 1;
                    DFS(grid, i, j, M, N);
                }
            }
        }
        return res;
    }
    void DFS(vector<vector<char> >& grid, int m, int n, int M, int N) {
        if (m < 0 || m >= M || n < 0 || n >= N) return;
        if (grid[m][n] == '1') grid[m][n] = '0';
        else return;
        DFS(grid, m + 1, n, M, N);
        DFS(grid, m - 1, n, M, N);
        DFS(grid, m, n + 1, M, N);
        DFS(grid, m, n - 1, M, N);
    }
};



int main() {
	Solution s;
    Examples eg;
    vector<vector<char> > grid;
    vector<char> line, line2;
    line.push_back(1);
    line.push_back(1);
    line2.push_back(0);
    line2.push_back(1);
    grid.push_back(line);
    grid.push_back(line2);
    string ss = "aaaaa";
    vector<int> v = {0, 1, 2, 3, 4, 5};
    v.push_back(11);

    char w = '1';
    cout << w << endl;
}
