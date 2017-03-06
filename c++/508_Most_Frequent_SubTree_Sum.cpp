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

/*Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node
 is defined as the sum of all the node values formed by the subtree rooted at that node (including the node 
 itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with 
 the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.*/

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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        if (root && !root->left && !root->right) {
            res.push_back(root->val);
            return res;
        }
        postOrder(root);
        mp[root->val]++;
        maximum = max(maximum, mp[root->val]);
        for (auto c: mp) {
            if (c.second == maximum)
                res.push_back(c.first);
        }
        return res;
    }

    void postOrder(TreeNode* &root) {
        if (!root) return;
        if (root && !root->left && !root->right) return;
        postOrder(root->left);
        postOrder(root->right);
        if (root->left) {
            mp[root->left->val]++;
            maximum = max(maximum, mp[root->left->val]);
            root->val += root->left->val;
            root->left->val = 0;
        }
        if (root->right) {
            mp[root->right->val]++;
            maximum = max(maximum, mp[root->right->val]);
            root->val += root->right->val;
            root->right->val = 0;
        }
        // mp[root->val]++; // should not consider parent node, or we should count it twice
        // cout << root->val << " times " << mp[root->val] << endl;
        // cout << " >> "  << root->val << endl;
        // maximum = max(maximum, mp[root->val]);
    }
private:
    unordered_map<int, int> mp;
    int maximum = INT_MIN;
};


int main() {
    Solution s;
    Examples eg;
    TreeNode* root = new TreeNode(5);
    TreeNode* root1 = new TreeNode(14);
    TreeNode* root2 = new TreeNode(1);
    root->left = root1;
    root1->left = root2;
    print(s.findFrequentTreeSum(root));
}