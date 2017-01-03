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

// instead of using recursion, we use iteration

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        stack<TreeNode*> stk;
        stk.push(root);

        while(!stk.empty()) {
            TreeNode* node = stk.top(); stk.pop();
            res.insert(res.begin(), node->val);
            if (node->left) stk.push(node->left);
            if (node->right) stk.push(node->right);
        }
        return res;
    }
};


int main() {
    Solution s;
    Examples eg;
}
