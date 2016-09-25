#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
    	TreeNode *first = NULL, *second = NULL, *prev = NULL; // must initialization
    	inorder(root, first, second, prev);
    	int tmp = first->val;
    	first->val = second->val;
    	second->val = tmp;
    }

    void inorder(TreeNode* root, TreeNode* &first, TreeNode* &second, TreeNode *&prev) {
    	if (!root)
    		return;
    	else {
    		inorder(root->left, first, second, prev);
    		if (!prev)
    			prev = root;
    		else{
    			if (prev->val > root->val) {
    				if (!first)
    					first = prev;
    				second = root;
    			}
    			prev = root;
    		}
    		inorder(root->right, first, second, prev);
    	}
    }
};

int main() {
	Solution s;
	TreeNode *a = new TreeNode(1);
	TreeNode *b = new TreeNode(0);
	b->left = a;
	s.recoverTree(b);

	TreeNode *c = NULL, *d;
	cout << c << " " << d << endl; // take care of difference, d has address without initialization, c is just NULL
	//0  0x400c00

}