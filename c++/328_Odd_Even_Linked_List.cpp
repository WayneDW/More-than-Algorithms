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

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* second = new ListNode(0), *newHead = head, *newSec = second;
        while (head->next->next) {
            second->next = head->next;
            head->next = head->next->next;
            head = head->next;
            second = second->next;
            if (!head->next) break;
        }
        if (head->next) {
            second->next = head->next;
            second->next->next = NULL;
        }
        else {
            second->next = NULL;
        }
        head->next = newSec->next;
        return newHead;
    }
};


int main() {
	Solution s;
    Examples eg;
    auto n1 = new ListNode(1);
    auto n2 = new ListNode(2);
    auto n3 = new ListNode(3);
    // auto n4 = new ListNode(4);
    // auto n5 = new ListNode(5);
    // auto n6 = new ListNode(6);
    // auto n7 = new ListNode(7);
    // auto n8 = new ListNode(8);
    n1->next = n2;
    n2->next = n3;
    // n3->next = n4;
    // n4->next = n5;
    // n5->next = n6;
    // n6->next = n7;
    // n7->next = n8;
    auto T = s.oddEvenList(n1);
    cout << T->next->next->next->val << endl;
}
