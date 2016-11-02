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

struct TreeLinkNode {
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
};

/*
        1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL*/

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> que;
        que.push(root);
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size - 1; i++) {
                TreeLinkNode* sub = que.front();
                que.pop();
                sub->next = que.front();
                if (sub->left) que.push(sub->left);
                if (sub->right) que.push(sub->right);
            }
            TreeLinkNode* sub = que.front();
            sub->next = NULL;
            que.pop();
            if (sub->left) que.push(sub->left);
            if (sub->right) que.push(sub->right);
        } 
    }
};


int main() {
	Solution s;
    Examples eg;
}
