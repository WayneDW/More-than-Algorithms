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
    bool isBalanced(TreeNode* root) {
        return dfs(root);
    }   
    bool dfs(TreeNode* root) {
        if (!root) return true;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        if ( abs(l - r) > 1) return false;
        else return dfs(root->left) && dfs(root->right);
    }
    
    int maxDepth(TreeNode * root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.isBalanced(eg.setTree0()) << endl;
}
