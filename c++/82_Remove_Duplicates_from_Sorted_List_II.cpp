#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

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
    ListNode* deleteDuplicates(ListNode* head) {
    	if (!head || !head->next)
    		return head;
        ListNode *p = new ListNode(-1);
        p->next = head;
        ListNode *left = p;
        ListNode *right = head;
        bool tag = 0;
        while (right) {
        	if (right->next && right->next->val == right->val){
        		tag = 1;
        		right->next = right->next->next;
        	} else if (tag) {
        		left->next = right->next;
        		right = right->next;
        		tag = 0;
        	} else {
        		left = right;
        		right = right->next;
        	}
        }
        return p->next;
    }
};


int main() {
    Solution s;
    Insert(1, 1);
	Insert(1, 2);
	Insert(2, 3);
	ListNode *tmp = head;
    while (tmp != NULL){
    	cout << "original val: " << tmp->val << " next: " << tmp->next << " address: " << tmp << endl;
    	tmp = tmp->next;
    }
    
    
    ListNode *out = s.deleteDuplicates(head);
    while (out != NULL){
    	cout << "val after change: " << out->val << " next: " << out->next << " address: " << out << endl;
    	out = out->next;
    }
}