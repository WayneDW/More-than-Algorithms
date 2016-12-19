#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include "func.cpp"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root || k <= 0) return 0;
        stack<TreeNode*> stk;
        while (root || !stk.empty()) {
            if (root) {
                stk.push(root);
                root = root->left;
            } else {
                root = stk.top();
                if (k-- == 1) return root->val;
                stk.pop();
                root = root->right;
            }
        }
        return 0;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int num = 0, res = 0;
        inorder(root, k, num, res);
        return res;
    }

    void inorder(TreeNode* root, int k, int &num, int &res) {
        if (!root) return;
        if (root->left) inorder(root->left, k, num, res);
        num++;
        if (num == k) {
            res = root->val;
            return;
        }
        if (root->right) inorder(root->right, k, num, res);
    }
};



int main() {
    Solution s;
    Examples eg;
    TreeNode* t= new TreeNode(1);
    TreeNode* t1= new TreeNode(2);
    t->right = t1;
    cout << s.kthSmallest(t, 2) << endl;

}
