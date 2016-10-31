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
    void flatten(TreeNode* root) {
        if (!root) return;
        vector<TreeNode*> res;
        preorder(root, res);
        int n = res.size();
        for (int i = 0; i < n - 1; i++) {
            res[i]->left = NULL;
            res[i]->right = res[i + 1];
        }
        res[n - 1]->left = res[n - 1]->right = NULL;
    }

    void preorder(TreeNode* root, vector<TreeNode*>& res) {
        if (!root) return;
        res.push_back(root);
        preorder(root->left, res);
        preorder(root->right, res);
    }
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return;
        if (root->left) flatten(root->left);
        if (root->right) flatten(root->right);
        if (root->left && root->right) {
            TreeNode* tmp = root->left;
            root->left = NULL;
            TreeNode* tmp2 = tmp;
            while (tmp2->right) tmp2 = tmp2->right;            
            tmp2->right = root->right;
            root->right = tmp;
        }
        else if (root->left && !root->right) {
            cout << root->left->val;
            root->right = root->left;
            root->left = NULL;
        }
    }
};



int main() {
	Solution2 s;
    Examples eg;
    TreeNode* t0 = new TreeNode(1);
    TreeNode* t1 = new TreeNode(2);
    TreeNode* t2 = new TreeNode(3);
    TreeNode* t3 = new TreeNode(4);
    t0->left = t1;
    t1->left = t2;
    t1->right = t3;
    s.flatten(t0);

}
