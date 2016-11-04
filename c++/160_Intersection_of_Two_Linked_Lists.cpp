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

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;
        ListNode* newHeadA = new ListNode(INT_MAX);
        ListNode* newHeadB = new ListNode(-INT_MAX);
        newHeadA->next = headA;
        newHeadB->next = headB;
        ListNode* lA = newHeadA, *lB = newHeadB;
        stack<ListNode*> qA, qB;
        while (lA) {
            qA.push(lA);
            lA = lA->next;
        }
        while (lB) {
            qB.push(lB);
            lB = lB->next;
        }
        if (qA.top()->val != qB.top()->val) return NULL;
        while (1) {
            if (qA.top()->val == qB.top()->val){
                qA.pop();
                qB.pop();
                continue;
            }
            else break;
        }
        return qA.top()->next;

    }
};

int main() {
	Solution s;
    Examples eg;
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(1);
    ListNode *c = s.getIntersectionNode(a, b);
    cout << c->val << endl;
}
