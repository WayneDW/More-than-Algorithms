#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        if (root->left) 
            int Tleft = maxDepth(root->left);
        if (root->right)
            int Tright = maxDepth(root->right);
        int res = max(1 + maxDepth(root->left), 1 + max(root->right));
        return res;
    }
};

int main() {
	Solution s;
}
