#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <algorithm>
#include <typeinfo>
#include "func.cpp"

using namespace std;

/*
[3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7

[
  [3],
  [9,20],
  [15,7]
]*/

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode* root) {
        vector<vector<int> > res;
        queue<TreeNode*> Q;
        if (!root) return res;
        Q.push(root);
        while (!Q.empty()) {
            vector<int> level;
            int size = Q.size();
            for (int i = 0; i < size; i++) { // make sure to be in the same level
                TreeNode* subtree = Q.front();
                Q.pop();
                level.push_back(subtree->val);
                if (subtree->left) Q.push(subtree->left);
                if (subtree->right) Q.push(subtree->right);
            }
            res.push_back(level);
        }
        return res;
    }
};

int main() {
    Solution s;
    Examples eg;

    vector<vector<int> > res = s.levelOrder(eg.setTree0());
    print2dVector(res);
}
