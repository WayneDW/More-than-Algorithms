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


/*my solution is like this: using two pointers, one of them one step at a time. 
another pointer each take two steps. Suppose the first meet at step k,
the length of the Cycle is r. so..2k-k=nr,k=nr
Now, the distance between the start node of list and the start node of cycle is s. 
the distance between the start of list and the first meeting node is k.
the distance between the start node of cycle and the first meeting node is m, so...s=k-m,
s=nr-m=(n-1)r+(r-m),here we takes n = 1..so, using one pointer start from 
the start node of list, another pointer start from the first meeting node, 
all of them wake one step at a time, the first time they meeting each other 
is the start of the cycle.

            cycle length r

----->------->-------->---  cycle point, step s
            |            |  distance m
            |            *  meeting point, step k
            |--<----<----|

after they meet, set slow at starting point, after s steps, slow is at s, fast from k to s also uses r - m = s steps
*/

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
                if (!fast->next) return NULL;
                if (slow == fast) break;
            }
            else return NULL;
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
