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

// DFS 

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        DFS(root, res, "");
        return res;
    }

    void DFS(TreeNode* root, int& res, string s) {
        if (root) {
            if (root->left) DFS(root->left, res, s + to_string(root->val));
            if (root->right) DFS(root->right, res, s + to_string(root->val));
            if (!root->left && !root->right) {
                s += to_string(root->val);
                res += stoi(s);
            }
        }
        else res += stoi(s);
    }
};

int main() {
	Solution s;
    Examples eg;
    TreeNode *t0 = new TreeNode(1);
    TreeNode *t1 = new TreeNode(2);
    TreeNode *t2 = new TreeNode(3);
    TreeNode *t3 = new TreeNode(1);

    t0->left = t1;
    t0->right = t2;
    //t1->right = t3;
    cout << s.sumNumbers(t0) << endl;
}
