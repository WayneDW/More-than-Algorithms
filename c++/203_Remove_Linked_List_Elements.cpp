#include <iostream>
#include <vector>
#include <map>
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

/*Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5*/


class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        if (head->val == val) return removeElements(head->next, val);
        ListNode* p = head;
        while (p->next) {
            if (p->next->val == val) p->next = p->next->next;
            else p = p->next;
        }
        return head;
    }
};


int main() {
    Solution s;
    Examples eg;
}
