#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <climits>
#include <math.h>

using namespace std;


// * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution { // bug version
public:
    bool isValidBST(TreeNode* root) {
        if (root)
            return check(root, INT_MIN, INT_MAX);
        else
            return true;
    }

    bool check(TreeNode *root, int Tmin, int Tmax) {
        bool isLeft = true, isRight = true;
        if (root->val > Tmax || root->val < Tmin || root->val == INT_MAX || root->val == INT_MIN)
            return false;
        if (root->left)
            isLeft = check(root->left, Tmin, root->val - 1);
        if (root->right)
            isRight = check(root->right, root->val + 1, Tmax);
        return isRight && isLeft;
    }
};

// tricky version, harder to understand
class Solution1 {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode *prev = NULL;
        return inorder(root, prev);
    }
    bool inorder(TreeNode *root, TreeNode * &prev) {
        if (!root) return true;
        if (!inorder(root->left, prev)) return false;
        if (prev && root->val <= prev->val) return false;
        prev = root;
        return inorder(root->right, prev);
    }
};

class Solution { // easier to understand version
public:
    bool isValidBST(TreeNode* root) {
        if (!root || (!root->left && !root->right)) return true;
        vector<int> res;
        inorder(root, res);
        for (int i = 1; i < res.size(); i++) {
            if (res[i] <= res[i-1]) return false;
        }
        return true;
    }
    void inorder(TreeNode* root, vector<int> &res) {
        if (!root) return;
        if (root->left) inorder(root->left, res);
        res.push_back(root->val);
        if (root->right) inorder(root->right, res);
    }
};

int main() {
    Solution2 s;
    TreeNode *a = new TreeNode(1);
    TreeNode *a1 = new TreeNode(2);
    TreeNode *a2 = new TreeNode(3);
    a->left = a1;
    a->right = a2;

    TreeNode *b = new TreeNode(-2147483648);
    TreeNode *c = new TreeNode(2147483647);
    TreeNode *c1 = new TreeNode(2147483647);
    c->left = c1;
    cout << s.isValidBST(c) << endl;
}