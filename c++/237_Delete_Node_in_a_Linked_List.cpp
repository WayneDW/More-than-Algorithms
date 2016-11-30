#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;


/*Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with 
value 3, the linked list should become 1 -> 2 -> 4 after calling your function.*/

class Solution {
public:
    void deleteNode1(ListNode* node) {
        *node = *node->next;
    }
    void deleteNode2(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
    void deleteNode(ListNode* node) { // for fear of memory leaking
        auto next = node;
        node = next->next;
        delete next;
    }
};

int main() {
	Solution s;
    Examples eg;
}
