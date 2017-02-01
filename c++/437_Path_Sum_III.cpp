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

/*You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11*/

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root) return 0;
        return newSum(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
private:
    int newSum(TreeNode*root, int prev, int sum) {
        if (!root) return 0;
        int cur = prev + root->val;
        return (cur == sum) + newSum(root->left, cur, sum) + newSum(root->right, cur, sum);
    }
};

int main() {
    Solution s;
    Examples eg;
    // TreeNode* t0 = new TreeNode(10);
    // TreeNode* t1 = new TreeNode(5);
    // TreeNode* t2 = new TreeNode(-3);
    // TreeNode* t3 = new TreeNode(3);
    // TreeNode* t4 = new TreeNode(2);
    // TreeNode* t5 = new TreeNode(11);
    // TreeNode* t6 = new TreeNode(3);
    // TreeNode* t7 = new TreeNode(-2);
    // TreeNode* t8 = new TreeNode(1);
    // t0->left = t1; t0->right = t2;
    // t1->left = t3; t1->right = t4;
    // t2->right = t5;
    // t3->left = t6; t3->right = t7;
    // t4->right = t8;
    // cout << s.pathSum(t0, 8) << endl;

    TreeNode* tt0 = new TreeNode(1);
    TreeNode* tt1 = new TreeNode(2);
    TreeNode* tt2 = new TreeNode(3);
    TreeNode* tt3 = new TreeNode(4);
    tt0->right = tt1; tt1->right = tt2; tt2->right = tt3;
    cout << s.pathSum(tt0, 3) <<  endl;
}
