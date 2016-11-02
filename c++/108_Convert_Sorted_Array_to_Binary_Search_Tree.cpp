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
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution2 { // wrong answer
public: // binary search tree root value > left tree value
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return NULL;
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(nums[0]);
        int s = 1;
        q.push(root);
        while (!q.empty() && s < n) {
            TreeNode* sub = q.front();
            q.pop();
            TreeNode* sL = new TreeNode(nums[s]);
            sub->left = sL;
            q.push(sL);
            s++;
            if (s < n) {
                TreeNode* sR = new TreeNode(nums[s]);
                sub->right = sR;
                q.push(sR);
                s++;
            }
        }
        return root;
    }
};

class Solution {
public: // binary search tree root value > left tree value
    TreeNode* sortedArrayToBST(vector<int> & nums) {
        return DFS(nums, 0, nums.size() - 1);
    }

    TreeNode* DFS(vector<int> &nums, int left, int right) {
        if (left > right) return NULL;
        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = DFS(nums, left, mid - 1);
        root->right = DFS(nums, mid + 1, right);
        return root;
    }
};


int main() {
	Solution s;
    Examples eg;
    vector<int> vec;
    vec.push_back(1);
    TreeNode* root = s.sortedArrayToBST(vec);

}
