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

/*Given a binary tree, find the leftmost value in the last row of the tree.

Example 1:
Input:

    2
   / \
  1   3

Output:
1
Example 2: 
Input:

        1
       / \
      2   3
     /   / \
    4   5   6
       /
      7

Output:
7
Note: You may assume the tree (i.e., the given root node) is not NULL.*/


class Solution_BFS {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front(); q.pop();
                if (i == 0) res = node->val;
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        return res;
    }
};

class Solution_DFS {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (!root) return 0;
        dfs(root, 0);
        return stk.top().second;
    }

    void dfs(TreeNode* root, int depth) {
        if (!root) return;
        dfs(root->left, depth + 1);
        if (stk.empty() || depth > stk.top().first)
            stk.push(make_pair(depth, root->val));
        dfs(root->right, depth + 1);
    }
private:
    stack<pair<int, int>> stk;
};


int main() {
    Solution s;
    Examples eg;
    TreeNode* root = new TreeNode(2);
    TreeNode* l = new TreeNode(1);
    TreeNode* r = new TreeNode(3);
    root->left = l; root->right = r;
    cout << s.findBottomLeftValue(root) << endl;
}