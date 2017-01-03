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


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }

    void dfs(TreeNode* root, vector<int> &res) {
        if (root) {
            res.push_back(root->val);
            if (root->left) dfs(root->left, res);
            if (root->right) dfs(root->right, res);
        }
    }
};

int main() {
    Solution s;
    Examples eg;
}
