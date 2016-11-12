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
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* next;
        while (head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};

// recursive method
/*
                        NULL
                           \
      1    ->    2    ->    3    <-    4    -> NULL
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
        if (!head && !head->next) return head;
        ListNode* node = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
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
    cout << res->next->val << endl;
}
