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


class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        return dfs(root, sum);
    }
    bool dfs(TreeNode* root, int sum) {
        if (!root) {
            if (sum == 0)
                return true;
            else
                return false;
        }
        int v = sum - root->val;
        if (!root->left && root->right) return dfs(root->right, v);
        else if (root->left && !root->right) return dfs(root->left, v);
        else return dfs(root->left, v) or dfs(root->right, v);
    }
};



int main() {
	Solution s;
    Examples eg;
    TreeNode* t0 = new TreeNode(1);
    TreeNode* t1 = new TreeNode(2);
    t0->left = t1;
    cout << s.hasPathSum(t0, 1) << endl;

}
