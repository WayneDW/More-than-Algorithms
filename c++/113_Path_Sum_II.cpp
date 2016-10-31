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
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > res;
        if (!root) return res;
        vector<int> tmp;
        dfs(root, sum, tmp, res);
        return res;
    }
    void dfs(TreeNode* root, int sum, vector<int> tmp, vector<vector<int> > & res) {
        if (!root) {
            if (sum == 0)
                res.push_back(tmp);
            return;
        }
        int v = root->val;
        tmp.push_back(v);
        if (root->left) dfs(root->left, sum - v, tmp, res);
        if (root->right) dfs(root->right, sum - v, tmp, res);
        if (!root->left && !root->right) {
            if (sum == v)
                res.push_back(tmp);
            return;
        } 
    }
};


int main() {
	Solution s;
    Examples eg;
}
