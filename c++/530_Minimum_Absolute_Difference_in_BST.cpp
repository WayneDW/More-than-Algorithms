#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
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

/*Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> vec;
        inorder(root, vec);
        int res = INT_MAX;
        for (int i = 1; i < vec.size(); i++) {
            res = min(vec[i] - vec[i-1], res);
        }
        return res;
    }

    void inorder(TreeNode* root, vector<int> &vec) {
        if (!root) return;
        inorder(root->left, vec);
        if (root) vec.push_back(root->val);
        inorder(root->right, vec);
    }
};

class Solution_no_vector_version {
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> vec;
        inorder(root);
        return min_diff;
    }

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (val >= 0) min_diff = min(min_diff, root->val - val);
        val = root->val;
        inorder(root->right);
    }
private:
    int val = -1, min_diff = INT_MAX;
};

int main() {
    Solution s;
    Examples eg;
}
