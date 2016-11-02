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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* tmp = head;
        while (tmp) {
            tmp = tmp->next;
            n++;
        }
        return cutHalf(head, 0, n - 1);      
    }
    TreeNode* cutHalf(ListNode* &head, int left, int right) {
        if (left > right) return NULL;
        int mid = left + (right - left) / 2;
        TreeNode* leftT = cutHalf(head, left, mid - 1);
        TreeNode* root = new TreeNode(head->val);
        head = head->next;
        TreeNode* rightT = cutHalf(head, mid + 1, right);
        root->left = leftT;
        root->right = rightT;
        return root;
    }
};


int main() {
	Solution s;
    Examples eg;
}
