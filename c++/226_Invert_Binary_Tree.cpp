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
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                auto T = q.front();
                q.pop();
                TreeNode *Tl = NULL, *Tr = NULL;
                if (T->left) Tl = T->left;
                if (T->right) Tr = T->right;
                T->left = Tr;
                T->right = Tl;
                if (T->left) q.push(T->left);
                if (T->right) q.push(T->right);
            }
        }
        return root;
    }
};


int main() {
	Solution s;
    Examples eg;
    TreeNode* t1 = new TreeNode(1);
    TreeNode* t2 = new TreeNode(2);
    TreeNode* t3 = new TreeNode(3);
    TreeNode* t4 = new TreeNode(4);
    TreeNode* t5 = new TreeNode(5);
    t1->left = t2;
    t1->right = t3;
    t2->left = t4;
    t3->right = t5;
    auto T = s.invertTree(t1);
    cout << T->left->left->val << endl;


}
