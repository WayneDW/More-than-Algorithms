#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
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

/*One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. 
If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false*/


/*  Idea: a tree has 3 parts:  root has 0 in-degree and 2 out-degree
                               node has 1 in-degree and 2 out-degree
                               null has 1 in-degree and 0 out-degree


        9
       / \    9, #, 92, #, #, 
      #  92

    cnt: the number of node that can be put in the tree*/

class Solution {
public:
    bool isValidSerialization(string preorder) {
        preorder += ',';
        int cnt = 1;
        for (int i = 0; i < preorder.size(); i++) {
            if (preorder[i] != ',') continue; // to handle digits more than 10
            cnt--;
            if (cnt < 0) return false;
            if (preorder[i - 1] != '#') cnt += 2;
        }
        return cnt == 0;
    }
};

int main() {
    Solution s;
    Examples eg;
}
