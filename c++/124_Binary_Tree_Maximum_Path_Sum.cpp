#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;


class Solution {
    int postOrder(TreeNode* root, int & maxSum) {
        if (!root) return 0;
        int l = max(0, postOrder(root->left, maxSum));
        int r = max(0, postOrder(root->right, maxSum));
        maxSum = max(maxSum, l + r + root->val);
        return root->val + max(l, r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        postOrder(root, maxSum);
        return maxSum;
    }
};

int main() {
	Solution s;
    Examples eg;
}
