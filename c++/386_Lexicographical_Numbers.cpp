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


/* brilliant idea: regard the digits as a tree, use preorder to traverse
         1           2           3            4 
        / \        /   \       /   \         / \
       10 ..      20 21 22    .....
      /  \
    100  ....
    Don't try to build the tree yourself, just think of the numbers as a 10-tree*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i < 10; i++)
            dfs(i, n, res);
        return res;
    }
    void dfs(int cur, int n, vector<int> &res) {
        if (cur > n) return;
        else {
            res.push_back(cur);
            for (int i = 0; i < 10; i++) {
                if (cur * 10 + i > n) return;
                dfs(cur * 10 + i, n, res);
            }
        }
    }
};


int main() {
	Solution s;
    Examples eg;
    vector<int> res = s.lexicalOrder(1123);
    print1dVector(res);
}
