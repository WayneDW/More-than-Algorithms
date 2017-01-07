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


class Solution_SLOW { // didn't utilize the property of complete binary tree, TLE
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int num = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front(); q.pop();
                num++;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return num;
    }
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode* left = root, *right = root;
        int lheight = 0, rheight = 0;
        while (left) {lheight++; left = left->left;}
        while (right) {rheight++; right = right->right;}
        if (lheight == rheight) return pow(2, lheight) - 1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

int main() {
    Solution s;
    Examples eg;
    TreeNode* t = new TreeNode(1);
    TreeNode* l = new TreeNode(1);
    TreeNode* r = new TreeNode(1);
    t->left = l;
    t->right = r;
    cout << s.countNodes(t) << endl;
}
