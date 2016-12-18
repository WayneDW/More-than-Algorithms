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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        int h = 1;
        while (!q.empty()) {
            h++;
            int size = q.size();
            vector<int> level;
            for (int i = 0; i < size; i++) {
                TreeNode* sub = q.front();
                q.pop();
                level.push_back(sub->val);
                if (sub->left) q.push(sub->left);
                if (sub->right) q.push(sub->right);
            }
            if (h % 2) reverse(level.begin(), level.end());
            res.push_back(level);
        }
        return res;
    }
};


int main() {
    Solution s;
    Examples eg;
    TreeNode *t0 = new TreeNode(3);
    TreeNode *t1 = new TreeNode(9);
    TreeNode *t2 = new TreeNode(20);
    TreeNode *t3 = new TreeNode(15);
    TreeNode *t4 = new TreeNode(17);
    t0->left = t1;
    t0->right = t2;
    t1->left = NULL;
    t1->right = NULL;
    t2->left = t3;
    t2->right = t4;
    print2dVector(s.zigzagLevelOrder(eg.setTree0()));
}
