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

/*Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]*/



class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        if (!root) return paths;
        string s;
        DFS(root, s, paths);
        return paths;
    }

    void DFS(TreeNode* root, string ss, vector<string> &paths) {
        if (!root->left && !root->right) {
            paths.push_back(ss + to_string(root->val));
            return;
        }
        else {
            ss += to_string(root->val);
            if (root->left) DFS(root->left, ss + '-' + '>', paths);
            if (root->right) DFS(root->right, ss + '-' + '>', paths);
        }
    }
};



int main() {
    Solution s;
    Examples eg;
    TreeNode *t = new TreeNode(1);
    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(3);
    TreeNode *t3 = new TreeNode(4);
    t->left = t1;
    t->right = t2;
    t1->right = t3;
    printVector(s.binaryTreePaths(t));
}
