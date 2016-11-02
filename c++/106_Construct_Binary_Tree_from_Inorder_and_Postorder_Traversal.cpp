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
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() != postorder.size()) return NULL;
        int n = inorder.size();
        return construct(inorder, postorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* construct(vector<int>& inorder, vector<int>& postorder, int s1, int e1, int s2, int e2) {
        if (s1 > e1 || s2 > e2) return NULL;
        int idx = -1;
        for (int i = s1; i <= e1; i++) {
            if (inorder[i] == postorder[e2]) {
                idx = i;
                break;
            }
        }
        if (idx == -1) return NULL;
        TreeNode* root = new TreeNode(postorder[e2]);
        root->left = construct(inorder, postorder, s1, idx - 1, s2, s2 - s1 + idx - 1);
        root->right = construct(inorder, postorder, idx + 1, e1, e2 - e1 + idx, e2 - 1);
        return root;
    }
};


int main() {
	Solution s;
    Examples eg;
}
