#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include "func.cpp"

using namespace std;


class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode* root) {
        vector<vector<int> > res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            vector<int> level;
            int size = q.size();
            for (int i = 0; i < size; i++) { // make sure to be in the same level
                TreeNode* sub = q.front();
                q.pop();
                level.push_back(sub->val);
                if (sub->left) q.push(sub->left);
                if (sub->right) q.push(sub->right);
            }
            res.push_back(level);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
	Solution s;
    Examples eg;
    vector<vector<int> > res = s.levelOrderBottom(eg.setTree0());
    print2dVector(res);

}
