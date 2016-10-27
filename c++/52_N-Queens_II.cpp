#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> cols;
        int allSol = 0;
        dfs(0, n, cols, allSol);
        return allSol;
    }

    void dfs(int irow, int n, vector<int> cols, int &allSol) {
        if (irow == n) {
            allSol++;
            return;
        }
        for (int icol = 0; icol < n; icol++) {
            if (isValid(irow, icol, cols)) {
                cols.push_back(icol);
                dfs(irow + 1, n, cols, allSol);
                cols.pop_back();
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
	Solution s;
}