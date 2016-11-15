#include <iostream>
#include <vector>
#include <map>
#include <cmath>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode *head = new ListNode(0);
    	ListNode *tmp = head;
    	while (l1 && l2) {
    		if (l1->val < l2->val) {
    			tmp->next = l1;
    			l1 = l1->next;
    		}
    		else{
    			tmp->next = l2;
    			l2 = l2->next;
    		}
    		tmp = tmp->next;
    	}
    	// useful commands
    	tmp->next = l1 ? l2 : l1;
    	return head->next;
    }
};


int main() {
    Solution s;
    
}
