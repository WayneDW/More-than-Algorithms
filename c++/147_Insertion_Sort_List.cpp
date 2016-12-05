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


/*

    x -> x -> x -> x -> x -> NULL
    i    j    k

*/

class Solution_wrong_version {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        auto i = head, j = head, k = head->next;  
        if (!head->next->next && head->val == head->next->val) return head;

        while (k) {
            j = k;
            k = j->next;
            while (i != k && i->next && i->next->val < j->val)
                i = i->next;

            auto p = i;
            while (p->next != j) p = p->next;
            if (i->val > j->val) {   /* 9 -> 10 -> 8 -> 12*/
                j->next = i;         /* i     p    j    k */
                p->next = k;
                head = j;
            }
            
            else if (i->next->val >= j->val) {  //   10->12->11->15 */
                j->next = i->next;             //    i       j   k */
                i->next = j;
                p->next = k;
            }
            else if (i->val < j->val) {
                i->next = j;
                j->next = k;
            }
            
            i = head;
        }
        return head;
    }
};

// hard part: how to avoid repeated values.
// reference https://discuss.leetcode.com/topic/13032/my-c-solution
class Solution {
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
    
        ListNode *p = head->next;
        head->next = NULL;
    
        while (p != NULL)
        {
            ListNode *pNext = p->next;    /*store the next node to be insert*/
            ListNode *q = head;
    
            if (p->val < q->val)    /*node p should be the new head*/
            {
                p->next = q;
                head = p;
            }
            else 
            {   // excellent dealing with repeated values
                /*
                9--->10--->10--->12
                q          p
                    ---->  q

                9---->10--->12--->10---->x
                q                 p
                       q
                */
                while (q != NULL && q->next != NULL && q->next->val <= p->val)
                    q = q->next;
                p->next = q->next;
                q->next = p;
            }
    
            p = pNext;
        }
        return head;
    }
};

int main() {
    Solution s;
    Examples eg;
    ListNode* node = new ListNode(4);
    ListNode* nod1 = new ListNode(2);
    ListNode* nod2 = new ListNode(1);
    ListNode* nod3 = new ListNode(3);
    // ListNode* nod7 = new ListNode(5);
    // ListNode* nod8 = new ListNode(11);
    // ListNode* nod9 = new ListNode(15);
    node->next = nod1;
    nod1->next = nod2;
    nod2->next = nod3;
    // nod3->next = nod4;
    // nod4->next = nod5;
    // nod5->next = nod6;
    // nod3->next = nod7;
    // nod7->next = nod8;
    // nod8->next = nod9;
    auto res = s.insertionSortList(node);
    cout << res->next->next->next->val << endl;
}
