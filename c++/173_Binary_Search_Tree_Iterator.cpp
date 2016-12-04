#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;


/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class BSTIterator {
    queue<int> q;
public:
    BSTIterator(TreeNode *root) {
        inorderTraverse(root);
    }

    void inorderTraverse(TreeNode *root) {
        if (!root) return;
        inorderTraverse(root->left);
        q.push(root->val);
        inorderTraverse(root->right);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return q.empty()? false: true;
    }

    /** @return the next smallest number */
    int next() {
        int res = q.front();
        q.pop();
        return res;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main() {
    
    Examples eg;
    TreeNode* t0 = new TreeNode(1);
    TreeNode* t1 = new TreeNode(2);
    TreeNode* t2 = new TreeNode(3);
    t0->left = t1;
    t0->right = t2;
    BSTIterator s = new BSTIterator(t0);
    cout << s.hasNext() << endl;

}
