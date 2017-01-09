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

/*Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined 
between two nodes v and w as the lowest node in T that has both v and w as descendants 
(where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA 
of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.*/


// dont try to remember its path

class Solution { // great idea
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* l = lowestCommonAncestor(root->left, p, q);
        TreeNode* r = lowestCommonAncestor(root->right, p, q);
        return !l? r: !r? l: root; 
    }
};

int main() {
    Solution s;
    Examples eg;
    TreeNode* root = new TreeNode(3);
    TreeNode* t0 = new TreeNode(5);
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(6);
    TreeNode* t3 = new TreeNode(2); //
    TreeNode* t4 = new TreeNode(0); //
    TreeNode* t5 = new TreeNode(8);
    TreeNode* t6 = new TreeNode(7);
    TreeNode* t7 = new TreeNode(4);
    root->left = t0;
    root->right = t1;
    t0->left = t2;
    t0->right = t3;
    t1->left = t4;
    t1->right = t5;
    t3->left = t6;
    t3->right = t7;
    TreeNode *res = s.lowestCommonAncestor(root, t5, t4);
}
