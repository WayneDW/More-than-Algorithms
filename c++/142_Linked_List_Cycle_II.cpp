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

// suppose the starting point S is L steps from the head 
// the crossing point is X steps away from S, the length of the circle is C
// (L + mC + X)*2 = L + nC + X ==> L = nC - X
// which means faster pointer can walk C - X steps to get to S which equals L

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;
        ListNode *slow = head, *fast = head;
        while (fast ->next) {
            slow = slow->next;
            fast = fast->next;
            if (fast->next) {
                fast = fast->next;
                if (!fast->next)
                    return NULL;
                if (slow == fast)
                    break;
            }
            else
                return NULL;
        }
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main() {
	Solution s;
    Examples eg;
}
