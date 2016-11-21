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


// 1, find the middle of a linked list, trick: fast and slow
// 2, use DFS postorder traverse, to merge
// 3, in the merge function, create a new node and combine the two and sort them

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode *slow = head, *fast = head, *prev = head; 
        while (fast && fast->next) { // split into two parts
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(slow);
        return merge(left, right);
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* head = new ListNode(INT_MIN);
        ListNode* newHead = head;
        while (left && right) {
            if (left->val < right->val) {
                newHead->next = left;
                left = left->next;
            }
            else {
                newHead->next = right;
                right = right->next;
            }
            newHead = newHead->next;
        }
        if (left) newHead->next = left;
        if (right) newHead->next = right;
        return head->next;
    }
};


int main() {
	Solution s;
    Examples eg;
}
