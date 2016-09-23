#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n == 0)
            return res;	
    	res = dfs(1, n);
    	return res;
    }

    vector<TreeNode*> dfs(int Tmin, int Tmax) {
    	vector<TreeNode*> res;
    	if (Tmin > Tmax) {
    		res.push_back(NULL);
    		return res;
    	}
    	for (int val = Tmin; val <= Tmax; val++) {
	    	vector<TreeNode*> leftTree = dfs(Tmin, val - 1);
	    	vector<TreeNode*> rightTree = dfs(val + 1, Tmax);
	    	for (int i = 0; i < leftTree.size(); i++) {
		    	for (int j = 0; j < rightTree.size(); j++) {
		    		TreeNode *root = new TreeNode(val);
		    		root->left = leftTree[i];
		    		root->right = rightTree[j];
		    		res.push_back(root);
		    	}
	    	}
    	}
    	return res;
    }
};

int main() {
	Solution s;
	vector<TreeNode*> res = s.generateTrees(0);

	for (int i = 0; i < res.size(); i++)
		cout << i << endl;
}