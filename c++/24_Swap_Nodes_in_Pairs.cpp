#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;

/**
 * Given a linked list, swap every two adjacent nodes and return its head.

 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.

 * Definition for singly-linked list.
**/

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode *head = NULL;

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

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
    	// build a longer linked list that points to the head node
    	ListNode *tmp = new ListNode(0);
    	tmp->next = head;
    	head = tmp;
    	// change head so that the structure of tmp would be saved.
    	while (head)
    		head = swapAdj(head->next);
    	return tmp->next;
    }
    ListNode *swapAdj(ListNode *&head) {
    	if (!head || !head->next)
    		return NULL;
    	ListNode *tail = head;
    	ListNode *nextNode = head->next->next;
    	head = head->next;
    	head->next = tail;
    	tail->next = nextNode;
    	return tail;
    }
};


int main() {
    Solution s;
    Insert(1, 1);
	Insert(2, 2);
	Insert(3, 3);
	Insert(4, 4);
	ListNode *tmp = head;
    while (tmp != NULL){
    	cout << "original val: " << tmp->val << " address: " << tmp << " next: " << tmp->next << endl;
    	tmp = tmp->next;
    }
    ListNode *out = new ListNode(0);
    out = s.swapPairs(head);
    cout << "? " << cout << endl;
    while (out != NULL){
    	cout << "original val: " << out->val << " address: " << out << " next: " << out->next << endl;
    	out = out->next;
    }

}
