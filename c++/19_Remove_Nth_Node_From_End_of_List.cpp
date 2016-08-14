#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;

/* Given linked list: 1->2->3->4->5, and n = 2.
** After removing the second node from the end, the linked list becomes 1->2->3->5.*/

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *head = NULL;


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	ListNode *first = head;
    	ListNode *second = head;
    	int i = 0;
    	
    	for (i = 0; i < n + 1 && first; i++)
    		first = first->next;

    	if (i == n + 1) { // delete non-head node
	    	while (first != NULL) {
	    		first = first->next;
	    		second = second->next;
	    	}
	    	second->next = second->next->next;
    	}
    	else { // delete head node
    		head = head->next;
    	}
     	return head;
    } 
};


void Insert(int data, int pos) {
	ListNode *tmp1 = new ListNode(0);
	tmp1->val = data;
	tmp1->next = NULL;
	if (pos == 1) {
		tmp1->next = head;
		head = tmp1;
		return;
	}
	
	ListNode *tmp2 = head;
	for (int i = 0; i < pos - 2;i++) {
		tmp2 = tmp2->next;
	}
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
}


int main() {
    Solution s;
    Insert(1, 1);
	Insert(2, 2);
	Insert(3, 3);
	Insert(4, 4);
	Insert(5, 5);
	ListNode *tmp = head;
    while (tmp != NULL){
    	cout << "original val: " << tmp->val << " address: " << tmp->next << endl;
    	tmp = tmp->next;
    }
    
    ListNode *out = s.removeNthFromEnd(head, 5);
    while (out != NULL){
    	cout << "val after change: " << out->val << " address: " << out->next << endl;
    	out = out->next;
    }
}
