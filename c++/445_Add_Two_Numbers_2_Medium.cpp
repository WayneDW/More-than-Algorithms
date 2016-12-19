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

/*You are given two linked lists representing two non-negative numbers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7*/
// Microsoft Bloomberg

using namespace std;

class Solution_slow {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l2) return l1;
        if (!l1) return l2;
        // get the length of listNode
        ListNode* tmp0 = l1, *tmp1 = l2;
        int lena = 0, lenb = 0;
        while (tmp0) {tmp0 = tmp0->next; lena++;};
        while (tmp1) {tmp1 = tmp1->next; lenb++;};
        int len = max(lena, lenb), t1 = len, t2 = len;
        stack<int> a, b;
        while (t1--) {
            if (t1 - lena >= 0) a.push(0);
            else {a.push(l1->val); l1 = l1->next;}
        }
        while (t2--) {
            if (t2 - lenb >= 0) b.push(0);
            else {b.push(l2->val); l2 = l2->next;}
        }
        int shift = 0;
        stack<int> out;
        while (!a.empty() && !b.empty()) {
            int sum = a.top() + b.top() + shift;
            shift = sum / 10;
            int left = sum % 10;
            out.push(left);
            a.pop(); b.pop();
        }
        ListNode* head;
        if (shift == 1) head = new ListNode(1);
        else head = new ListNode(0);

        ListNode *temp = head;
        while (!out.empty()) {
            ListNode* tmp = new ListNode(out.top());
            out.pop();
            temp->next = tmp;
            temp = tmp;
        }
        if (head->val == 0) head = head->next;
        return head;
    }
};



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l2) return l1;
        if (!l1) return l2;
        ListNode* head = NULL;
        stack<int> stkA, stkB;

        while (l1) {
            stkA.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            stkB.push(l2->val);
            l2 = l2->next;
        }

        int shift = 0;
        while (!stkA.empty() || !stkB.empty()) {

            if (!stkA.empty()) {
                shift += stkA.top();
                stkA.pop();
            }
            if (!stkB.empty()) {
                shift += stkB.top();
                stkB.pop();
            }
            ListNode* tmp = new ListNode(shift % 10);
            tmp->next = head;
            head = tmp;
            shift /= 10;
        }
        if (shift) {
            ListNode* tmp = new ListNode(shift % 10);
            tmp->next = head;
            head = tmp;
        }
        return head;
    }
};

int main() {
    Solution s;
    Examples eg;
    ListNode* l1 = new ListNode(9);
    ListNode* l2 = new ListNode(1);
    ListNode* l3 = new ListNode(9);
    ListNode* l4 = new ListNode(9);
    ListNode* l5 = new ListNode(9);
    ListNode* l6 = new ListNode(9);
    ListNode* l7 = new ListNode(9);
    ListNode* l8 = new ListNode(9);
    ListNode* l9 = new ListNode(9);
    ListNode* l10 = new ListNode(9);
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    l6->next = l7;
    l7->next = l8;
    l8->next = l9;
    l9->next = l10;
    ListNode* ll = s.addTwoNumbers(l1, l2);
    cout << ll->next->val << endl;
}
