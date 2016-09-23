#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;



struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
    	if (!p and !q) return true;
    	else if ((!p && q) || (p && !q)) return false;
    	else if (p->val == q->val) {
    		bool isLeft = isSameTree(p->left, q->left);
    		bool isRight = isSameTree(p->right, q->right);
    		if (isLeft and isRight)
    			return true;
    	}
    	return false;
    }
};

// class Solution {
// public:
//     bool isSameTree(TreeNode *p, TreeNode *q) {
//         if(!p && !q) return true;
//         if((!p && q) || (p && !q)) return false;
//         if(p->val != q->val) return false;
//         return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
//     }
// };


int main() {
	Solution s;

	TreeNode* a1 = new TreeNode(1);
	TreeNode* a3 = new TreeNode(1);
	a1->left = NULL;
	a1->right = a3;

	TreeNode* b1 = new TreeNode(1);
	TreeNode* b3 = new TreeNode(1);
	b1->left = NULL;
	b1->right = b3;
	cout << s.isSameTree(a1, b1) << endl;
}