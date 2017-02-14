#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;


/*The thief has found himself a new place for his thievery again. There is only one entrance to this area, 
called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart 
thief realized that "all houses in this place forms a binary tree". It will automatically contact the police 
if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.
Example 1:
     3
    / \
   2   3
    \   \ 
     3   1
Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:
     3
    / \
   4   5
  / \   \ 
 1   3   1
Maximum amount of money the thief can rob = 4 + 5 = 9.*/


class Solution_BFS { // can't work for case 4-1-2-3 -> 7 rather than 6
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int res[2] = {0}, layer = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front(); q.pop();
                res[layer % 2] += node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            layer++;
        }
        return max(res[0], res[1]);
    }
};


class Solution {
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        int l = 0, r = 0;
        return subRob(root, l, r);
    }

    int subRob(TreeNode* root, int &l, int &r) {
        if (!root) return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = subRob(root->left, ll, lr);
        r = subRob(root->right, rl, rr);
        return max(root->val + ll + lr + rl + rr, l + r);
    }
};


int main() {
    Solution s;
    Examples eg;
    TreeNode* t0 = new TreeNode(4);
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(3);
    t0->left = t1; t1->left = t2; t2->left = t3;
    cout << s.rob(t0) << endl;
}
