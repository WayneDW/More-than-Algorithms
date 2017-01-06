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

/*Find all possible combinations of k numbers that add up to a number n, given that 
only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.


Example 1:

Input: k = 3, n = 7   Output: [[1,2,4]]

Example 2:

Input: k = 3, n = 9   Output: [[1,2,6], [1,3,5], [2,3,4]]*/


/*The idea is to use DFS, however how can we avoid repeating? 
The trick here is to construct solution with sorted order*/

class Solution {
public:
    vector<vector<int> > combinationSum3(int k, int n) {
        vector<vector<int> > res;
        vector<int> cur;
        DFS(res, cur, k, n);
        return res;
    }

    void DFS(vector<vector<int> > &res, vector<int> cur, int k, int n) {
        if (k == cur.size() && n == 0) {
            res.push_back(cur);
            return;
        }
        for (int i = cur.empty() ? 1 : cur.back() + 1; i < 10; i++) { // cur.back() + 1 makes sure unique
            if (n - i < 0) break; // if n - i <= 0, there will be no result
            cur.push_back(i);
            DFS(res, cur, k, n - i);
            cur.pop_back();
        }
    }
};


int main() {
    Solution s;
    Examples eg;
    printVector(s.combinationSum3(2, 4));
}
