#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *l = head;
        int sum, carry = 0;
        while (l1 || l2 || carry) {
            sum = carry;
            carry = 0;
            if (l1) { // this way makes the code more simple
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (sum > 9) {
                sum -= 10;
                carry = 1;
            }
            l->next = new ListNode(sum);
            l = l->next;
        }
        return head->next;
    }
};

