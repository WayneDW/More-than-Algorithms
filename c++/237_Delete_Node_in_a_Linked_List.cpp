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
    void deleteNode2(ListNode* node) { // failed version
        auto temp = node;
        *node = *temp->next;
        cout << node << endl; 
        delete temp; // this delete didn't point a right next node
        cout << node << endl;
    }
    void deleteNode(ListNode* node) { // success version
        auto temp = node->next;
        *node = *temp;
        delete temp;
    }
};

int main() {
	Solution s;
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    s.deleteNode2(node2);
    cout << node1->next->val << endl;
}
