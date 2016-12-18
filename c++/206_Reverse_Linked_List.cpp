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


// Reverse a singly linked list.

// Uber Facebook Twitter Zenefits Amazon Microsoft Snapchat Apple Yahoo Bloomberg Yelp Adobe
// A linked list can be reversed either iteratively or recursively. Could you implement both?
/*
        1   ->   2   ->   3   ->   NULL
       inv      tmp
               pivot
NULL<-  1        2        3   ->   NULL
       inv               tmp    
               pivot
NULL<-  1   <-   2        3   ->   NULL
                inv      tmp
                        pivot
*/
class Solution_iterative {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* inv = head, *tmp = head->next, *pivot = tmp;
        inv->next = NULL;
        while (tmp) {
            tmp = tmp->next;
            pivot->next = inv;
            inv = pivot;
            pivot = tmp;
        }
        return inv;
    }
};

// concise solution
class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev(NULL), *nextN;
        while (head) {
            nextN = head->next;
            head->next = prev;
            prev = head;
            head = nextN;
        }
        return prev;
    }
};

// recursive method
/*
    step 1, recursion to head = 3, 4->next = 3
    step 2, here return node at 4
    step 3, go back to step at 2, here node is also 4, here update 3->next = 2
    step 4, ...

      1    ->    2    ->    3    ->    4    -> NULL

                        NULL
                           \
      1    ->    2    ->    3    <-    4       NULL
                                      node
                           head
              NULL
                \
      1    ->    2    <-    3    <-    4    -> NULL
                                      node
                head
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL; // this step only works at the last step
        return node;
    }
};

int main() {
	Solution s;
    Examples eg;
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    n1->next = n2;
    n2->next = n3;
    ListNode* res = s.reverseList(n1);
    cout << res->next->next->next->val << endl;
}
