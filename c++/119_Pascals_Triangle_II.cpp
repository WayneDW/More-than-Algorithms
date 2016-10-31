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


class Solution2 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;     
        res.push_back(1);
        if (rowIndex == 0) return res;
        if (rowIndex == 1) {
            res.push_back(1);
            return res;
        }
        vector<int> line = getRow(rowIndex - 1);
        for (int i = 0; i < rowIndex - 1; i++){
            res.push_back(line[i] + line[i + 1]);
        }
        res.push_back(1);
        return res;
    }
};


// math solution
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex + 1, 1);     
        if (rowIndex <= 1) return res;
        int i = rowIndex, p = 1;
        for (int k = 1; k < rowIndex / 2 + 1; k++)
            res[k] = (unsigned long long) res[k - 1] * i-- / k; // to avoid overflow
        for (int k = rowIndex / 2 + 1; k <= rowIndex; k++)
            res[k] = res[rowIndex - k];
        return res;
    }
};

int main() {
	Solution s;
    Examples eg;
    print1dVector(s.getRow(30));
}
