#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head)
            return head;
        ListNode *p = head;
        while (p->next){
            if (p->next->val == p->val)
                p->next = p->next->next;
            else
                p = p->next;
        }
        return head;
        
        
    }
};


int main() {



}
