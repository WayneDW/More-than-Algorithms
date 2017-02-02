#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

/*Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
    \
     2
    /
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).*/


// class Solution {
// private:
//     int local_cnt(TreeNode* node) {  // count the occurence of the same number for a certain node
//         int cnt = 0, lnum = 0, rnum = 0;
//         if (!node) return cnt;
//         if (node->left && node->val == node->left->val) lnum = local_cnt(node->left);
//         if (node->right && node->val == node->right->val) rnum = local_cnt(node->right);
//         return 1 + lnum + rnum;
//     }

//     void dfs(TreeNode* node, unordered_set<int> st, stack<pair<int,int>> &stk, int cnt, int last) {
//         if (!node) {
//             if (st.count(last) > 0) return;
//             if (cnt >= stk.top().second) {
//                 if (cnt > stk.top().second) {
//                     while (!stk.empty()) stk.pop();
//                     st.clear();
//                 }
//                 st.insert(last);
//                 stk.push(pair<int, int>(last, cnt));
//             }
//             return;
//         }
//         if (node->val != last) {
//             int cnt = local_cnt(node);
//             // if (last == 1) cout << cnt <<
//             st.insert(node->val);
//             if (stk.empty()) stk.push(pair<int,int>(node->val, cnt));
//             else if (cnt >= stk.top().second){
//                 if (cnt > stk.top().second) {
//                     while (!stk.empty()) stk.pop();
//                     st.clear();
//                 }
//                 st.insert(node->val);
//                 stk.push(pair<int,int>(node->val, cnt));
//             }
//         }
        
//         dfs(node->left, st, stk, cnt, node->val);
//         dfs(node->right, st, stk, cnt, node->val);
//     }
// public:
//     vector<int> findMode(TreeNode* root) {
//         vector<int> res;
//         if (!root) return res;
//         stack<pair<int, int>> stk;
//         unordered_set<int> st;
//         if (root->val == 0) dfs(root, st, stk, 1, 1);
//         else dfs(root, st, stk, 1, 0);
//         while (!stk.empty()) {
//             res.push_back(stk.top().first);
//             stk.pop();
//         }
//         return res;
//     }
// };

class Solution_extra_memory_version {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        unordered_map<int, int> mp;
        int maxV = INT_MIN;
        dfs(root, mp, maxV);
        for (auto c: mp) if (c.second == maxV) res.push_back(c.first);
        return res;
    }

    void dfs(TreeNode* root, unordered_map<int, int> &mp, int &maxV) {
        if (!root) return;
        mp[root->val]++;
        maxV = max(maxV, mp[root->val]);
        dfs(root->left, mp, maxV);
        dfs(root->right, mp, maxV);
    }
};

/* idea: inorder gives us sorted array, utilize this information
I used a stack<pair<int, int>> to remember the target result

if a new set of solutions comes out, pop the old one and push new

one trick here is to memorize the last value when we traverse the tree, I can't find a logic to express it now, instead I used a dq.


another trick is to consider the corner case, i.e. the last node and the case when there is one node*/


class Solution { // my own o(1) memory solution
    void inorder(TreeNode* &root, stack<pair<int, int>> &stk, int &cnt, deque<int> &dq) {
        if (!root) return; 

        inorder(root->left, stk, cnt, dq);
        dq.push_back(root->val);
        if (dq.size() > 2) dq.pop_front(); // trim deque when its length goes beyong 2     

        if (dq.front() == root->val) cnt++;
        else {
            if (dq.front() != INT_MIN && dq.front() != root->val && (stk.empty() || cnt >= stk.top().second)) {
                if (!stk.empty() && cnt > stk.top().second) while (!stk.empty()) stk.pop(); // when we meet better solution, clear the old one
                stk.push(pair<int, int>(dq.front(), cnt));
            }
            cnt = 1; // put it outside the above loop
        }

        inorder(root->right, stk, cnt, dq);
    }

public:
    vector<int> findMode(TreeNode* root) {
        int cnt = 1;
        vector<int> res;
        if (root && !root->left && !root->right) { // corner case: handle one-node example
            res.push_back(root->val);
            return res;
        }

        stack<pair<int, int>> stk;
        deque<int> dq;

        dq.push_back(INT_MIN); // insert a fake number, there should be better ways to handle this part. It has potentially bug
        inorder(root, stk, cnt, dq);

        if (dq.front() != INT_MIN  && (stk.empty() || cnt >= stk.top().second)) { // corner case: handle the last node
            if (!stk.empty() && cnt > stk.top().second) while (!stk.empty()) stk.pop();
            stk.push(pair<int, int>(dq.back(), cnt));
        }

        while (!stk.empty()) { // change result format
            res.push_back(stk.top().first);
            stk.pop();
        }
        return res;
    }
};

int main() {
    Solution s;
    Examples eg;
    TreeNode* t0 = new TreeNode(3);
    TreeNode* tl = new TreeNode(2);
    TreeNode* tr = new TreeNode(3);
    TreeNode* trl = new TreeNode(3);
    TreeNode* trr = new TreeNode(4);
    TreeNode* trrl = new TreeNode(4);
    TreeNode* trrr = new TreeNode(5);
    TreeNode* trrrl = new TreeNode(5);
    TreeNode* trrrr = new TreeNode(6);
    t0->left = tl;
    t0->right = tr;
    tr->left = trl;
    tr->right = trr;
    trr->left = trrl;
    trr->right = trrr;
    trrr->left = trrrl;
    trrr->right = trrrr;
    print(s.findMode(t0));

}


