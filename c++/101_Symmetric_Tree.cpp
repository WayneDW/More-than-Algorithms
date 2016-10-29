#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// recursion
/*
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSym(root, root);
    }
    bool isSym(TreeNode *tl, TreeNode *tr){
        if (!tl && !tr) return true;
        if ((!tl && tr) || (tl && !tr)) return false;
        // left subtree and right subtree both points to the same node
        if (tl == tr) return isSym(tl->left, tl->right);
        if (tl->val != tr->val) return false;
        return isSym(tl->left, tr->right) && isSym(tl->right, tr->left);
    }
};*/
// iteration
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> Tl, Tr;
        Tl.push(root->left);
        Tr.push(root->right);



        while (!Tl.empty() && !Tr.empty()) {
            TreeNode *lnode = Tl.front();
            TreeNode *rnode = Tr.front();
            Tl.pop();
            Tr.pop();

            if (!lnode && !rnode) continue; // can't return true, since here may be [9,-42,-42,null,76,76,null,null,13,null,13]
            if ((lnode && !rnode) ||(!lnode && rnode)) return false;
            if (lnode->val != rnode->val) return false;
            Tl.push(lnode->left);
            Tr.push(rnode->right);
            Tl.push(lnode->right);
            Tr.push(rnode->left);
        }
        if (!Tl.empty() || !Tr.empty()) return false;
        return true;
    }
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        
    }
};

int main() {
	Solution s;
    TreeNode *s0 = new TreeNode(1);
    TreeNode *s1 = new TreeNode(2);
    TreeNode *s2 = new TreeNode(2);
    s0->left = s1;
    s0->left = s2;
    cout << s.isSymmetric(s0) << endl;
}