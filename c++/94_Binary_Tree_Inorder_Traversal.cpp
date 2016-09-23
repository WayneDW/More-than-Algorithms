#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// simple iteration solution
class Solution1{
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		inOrder(root, res);
        return res;
    }

    void inOrder(TreeNode*Node, vector<int> & res) {
        if (!Node)
            return;
    	//if (Node->val == NULL)
    	//	return;
    	inOrder(Node->left, res);
    	res.push_back(Node->val);
    	inOrder(Node->right, res);
    }
};

/*
   1
  / \
 2   3
    /
   4
    \
     5
*/

class Solution{
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> stk;
		TreeNode *tmp = root;

		while (tmp or ! stk.empty()) {
			if (tmp) {
				stk.push(tmp);				
				tmp = tmp->left;
			}
			else {
				tmp = stk.top();
				stk.pop();
				res.push_back(tmp->val);
				tmp = tmp->right;
			}
		}
		return res;
	}
};


int main() {
	Solution s;
}