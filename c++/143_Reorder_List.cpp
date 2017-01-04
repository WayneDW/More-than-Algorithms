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

/*Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.*/

/*idea:
For 1 -> 2 -> 3 -> 4 -> 5 -> 6

Find middle point, and reverse
1 -> 2 -> 3 -> 4 -> 5 -> 6
to
1 -> 2 -> 3 -> 6 -> 5 -> 4
Finally, move 6 between 1 and 2, 5 between 2, 3...
1 -> 6 -> 2 -> 5 -> 3 -> 4*/

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        // find middle node
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // reverse the last half
        ListNode *prev = NULL, *cur = slow->next, *nNext = cur->next;
        while (cur) {
            cur->next = prev;
            prev = cur; cur = nNext;
            if (nNext) nNext = nNext->next;
        }
        slow->next = prev; // for case of 1->2->3 | 6->5->4, this makes sure 3->6

        // merge two lists
        ListNode *p1 = head, *p2 = slow->next, *rcur, *lcur;
        while (p1 != slow) { // stop at 3
            lcur = p1->next, rcur = p2->next; // record the next nodes
            p1->next = p2, p2->next = lcur; // 1->6, 6->2 ...
            p1 = lcur, p2 = rcur; // move to the next nodes
        }
        slow->next = p2; // the last nodes 3 still points to 6, update to 3->4
    }
};


int main() {
    Solution s;
    Examples eg;
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    ListNode *n6 = new ListNode(6);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n5; n5->next = n6;
    s.reorderList(n1);
    cout << n1->val << endl;
    cout << n1->next->val << endl;
    cout << n1->next->next->val << endl;
    cout << n1->next->next->next->val << endl;
    cout << n1->next->next->next->next->val << endl;
    cout << n1->next->next->next->next->next->val << endl;
    cout << n1->next->next->next->next->next->next << endl;
}
