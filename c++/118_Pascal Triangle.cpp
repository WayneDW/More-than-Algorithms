#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include "func.cpp"

using namespace std;


class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        if (numRows == 0) return res;
        vector<int> row;
        row.push_back(1);
        if (numRows == 1) {
            res.push_back(row);
            return res;
        }
        else if (numRows == 2) {
            res.push_back(row);
            row.push_back(1);
            res.push_back(row);
            return res;
        }
        vector<vector<int> > last = generate(numRows - 1);
        for (int i = 0; i < numRows - 2; i++) {
            row.push_back(last[numRows - 2][i] + last[numRows - 2][i + 1]);
        }
        row.push_back(1);
        last.push_back(row);
        return last;
    }
};

int main() {
    Solution s;
    Examples eg;
    vector<vector<int> > res = s.generate(4);
    print2dVector(res);
    

}