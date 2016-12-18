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

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */


class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeLinkNode *cur = q.front(); q.pop();
                if (i != n - 1) cur->next = q.front();
                else cur->next = NULL;
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
    }
};


int main() {
    Solution s;
    Examples eg;
}
