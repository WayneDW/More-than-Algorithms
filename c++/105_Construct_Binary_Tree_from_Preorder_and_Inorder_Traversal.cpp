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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int m = preorder.size(), n = inorder.size();
        if (m != n || n == 0) return NULL;
        return DFS(preorder, inorder, 0, m - 1, 0, n - 1);
    }
    // the address & is important, input address uses much less memory
    TreeNode* DFS(vector<int>& preorder, vector<int>& inorder, int s1, int e1, int s2, int e2) {
        if (s1 > e1 || s2 > e2) return NULL;
        int idx = -1;
        TreeNode* root = new TreeNode(preorder[s1]);
        for (int i = s2; i <= e2; i++) {
            if (preorder[s1] == inorder[i]) {
                idx = i;
                break;
            }
        }
        if (idx == -1) return NULL;
        root->left = DFS(preorder, inorder, s1 + 1, idx + s1 - s2, s2, idx - 1); // make sure the two parts have the same length
        root->right = DFS(preorder, inorder, e1 - e2 + idx + 1, e1, idx + 1, e2);
        return root;
    }
};
int main() {
	Solution2 s;
    Examples eg;
    vector<int> a, b;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    b.push_back(2);
    b.push_back(3);
    b.push_back(4);
    TreeNode* res = s.buildTree(a, b);
    if (res)
        cout << res->val << endl;

}
