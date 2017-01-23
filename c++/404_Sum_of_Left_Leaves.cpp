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

/*Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.*/


class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        return dfs(root, false);
    }
    int dfs(TreeNode* root, bool ifLeft) {
        if (root && !root->left && !root->right) {
            if (ifLeft) return root->val;
            else return 0;
        }
        int sum = 0, vleft = 0, vright = 0;
        if (root->left) vleft = dfs(root->left, true);
        if (root->right) vright = dfs(root->right, false);
        return sum + vleft + vright;
    }
};


int main() {
    Solution s;
    Examples eg;
    
}
