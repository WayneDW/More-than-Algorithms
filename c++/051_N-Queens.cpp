#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {
        vector<int> cols;
        vector<string> sol;
        vector<vector<string> > allSol;
        dfs(0, n, cols, sol, allSol);
        return allSol;
    }

    void dfs(int irow, int n, vector<int> cols, vector<string> sol, vector<vector<string> > &allSol) {
        if (irow == n) {
            allSol.push_back(sol);
            return;
        }
        for (int icol = 0; icol < n; icol++) {
            if (isValid(irow, icol, cols)) {
                string row(n, '.');
                row[icol] = 'Q';
                cols.push_back(icol);
                sol.push_back(row);
                dfs(irow + 1, n, cols, sol, allSol);
                cols.pop_back();
                sol.pop_back();
            }
        }

    }
    bool isValid(int irow, int icol, vector<int> cols) {
        for (int row = 0; row < cols.size(); row++) {
            if (icol == cols[row] or abs(irow - row) == abs(icol - cols[row]))
                return false;
        }
        return true;
    }
};


int main() {
	//Solution s;
    string s(5, '.');
}