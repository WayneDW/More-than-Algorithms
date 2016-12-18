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

class Solution {
public: // great idea, create two pointers
//the fast one will approach the slow one one step once
    bool hasCycle(ListNode *head) {
        while (!head) return false;
        ListNode *fast = head, *slow = head;
        while (slow->next && fast->next) {
            slow = slow->next;
            fast = fast->next;
            if (fast->next) {
                fast = fast->next;
                if (fast == slow) return true;
            }
            else break;
        }
        return false;
    }
};


int main() {
    Solution s;
    Examples eg;
    ListNode *n = new ListNode(1);
    n->next = n;
    cout << s.hasCycle(n) << endl;
}
