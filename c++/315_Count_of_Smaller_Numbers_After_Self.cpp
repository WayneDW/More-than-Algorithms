#include <iostream>
#include <vector>
#include <map>
#include <set>
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

/*You are given an integer array nums and you have to return a new counts array. The counts 
array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Given nums = [5, 2, 6, 1]

To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Return the array [2, 1, 1, 0].*/

/*https://discuss.leetcode.com/topic/31405/9ms-short-java-bst-solution-get-answer-when-building-bst
Every node will maintain a val sum recording the total of number on it's left bottom side, dup counts 
the duplication. 
For example, [3, 2, 2, 6, 1], from back to beginning, we would have:

                1(0, 1)       val=1, sum=0, dup=1
                 \ 
                  6(3, 1)     val=6, sum=3, dup=1
                 /
                2(0, 2)       val=2, sum=0, dup=2
                 \
                  3(0, 1)     val=3, sum=0, dup=1

When we try to insert a number, the total number of smaller number would be adding dup and sum of the 
nodes where we turn right.

if we insert 5, it should be inserted on the way down to the right of 3, the nodes where we turn right
is 1(0,1), 2(0,2), 3(0,1), so the answer should be (0 + 1)+(0 + 2)+ (0 + 1) = 4

if we insert 7, the right-turning nodes are 1(0,1), 6(3,1), so answer should be (0 + 1) + (3 + 1) = 5*/

class Solution {
    struct Node {
        int val, sum, dup = 1;
        Node* left, *right;
        Node(int v): val(v), sum(0), left(nullptr), right(nullptr) {}
    };

    Node* insert(int num, Node* node, vector<int> &res, int i, int preSum) {
        if (!node) {
            node = new Node(num);
            res[i] = preSum;
        }
        else if (node->val == num) {
            node->dup++;
            res[i] = preSum + node->sum;
        }
        else if (node->val > num) { 
            node->sum++;
            node->left = insert(num, node->left, res, i, preSum);
        }
        else {
            node->right = insert(num, node->right, res, i, preSum + node->dup + node->sum);
        }
        return node;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        Node *root = nullptr;
        for (int i = n - 1; i >= 0; i--) {
            root = insert(nums[i], root, res, i, 0); // every loop, we start at the root (v=1) node 
            // if (i == 2) cout << root->val << endl;
            // print(res);
        }    
        return res;
    }
};



int main() {
    Solution s;
    Examples eg;
    vector<int> nums = {3, 2, 2, 6, 1};
    print(s.countSmaller(nums));
}
