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

/*You need to find the largest value in each row of a binary tree.

Example:
Input: 

          1
         / \
        3   2
       / \   \  
      5   3   9 

Output: [1, 3, 9]*/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            int cur = INT_MIN;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front(); q.pop();
                cur = max(cur, node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(cur);
        }
        return res;
    }
};


int main() {
    Solution s;
    Examples eg;
    TreeNode* root = new TreeNode(2);
    TreeNode* l = new TreeNode(1);
    TreeNode* r = new TreeNode(3);
    root->left = l; root->right = r;
    print(s.largestValues(root));
}