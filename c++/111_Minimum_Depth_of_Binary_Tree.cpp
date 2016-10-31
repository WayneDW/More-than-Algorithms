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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        else if (!root->left && !root->right) return 1;
        else if (!root->left && root->right) return minDepth(root->right) + 1;
        else if (root->left && !root->right) return minDepth(root->left) + 1;        
        else return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};


int main() {
	Solution s;
    Examples eg;
}
