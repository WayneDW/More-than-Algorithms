#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>

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

/* wrong version
class Solution {
public:
	void reverseSet(ListNode* start, ListNode* end) {
    	ListNode *head = new ListNode(0);
    	head->next = start;
    	ListNode *startNext = start->next;
    	ListNode *endNext = end->next;
    	while (head->next != endNext) {
    		ListNode *tmp = startNext->next;
    		startNext->next = tmp->next;
    		tmp->next = head->next;
    		head->next = tmp;
    	}
    	delete head;
    	start->next = endNext;
    	start = startNext;
    	delete endNext;
    	delete startNext;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
    	if (!head)
    		return NULL;
    	ListNode* nhead = new ListNode(0);
    	nhead->next = head;
    	ListNode* start = nhead;
    	while (start->next) {
    		ListNode *end = start;
    		for (int i = 0; i < k - 1; i++) {
    			end = end->next;
    			if (not end->next)
    				return nhead->next;
    		}
    		reverseSet(start, end);
    	}
    	return nhead->next; 
    }
};*/

class Solution {
public:
    // p1->p1next->...->p2->p2next
    //      |____________|
    //   reverse this part to:
    // p1->p2->.......->p1next->p2next;
    // return p1next;
    ListNode *reverse(ListNode *p1, ListNode *p2) {
        ListNode *p1next = p1->next;
        ListNode *p2next = p2->next;
        ListNode *prev = p2next;
        ListNode *p = p1next; 
        
        while (p != p2next) {
            ListNode *temp = p ->next;
            p->next = prev;
            prev = p;
            p = temp;
        }
        p1->next = p2;
        return p1next;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) {
            return head;
        }
        
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode *p1 = dummy, *p2 = dummy;
        
        for (int i = 0; i < k; i++) {
            if (p2 == NULL) {
                break;
            }
            p2 = p2->next;
        }
        if (p2 == NULL) {
            return head;
        }
        
        while (p2 != NULL) {
            p2 = reverse(p1, p2);
            for (int i = 0; i < k; i++) {
                if (p2 == NULL) {
                    break;
                }
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        
        return dummy->next;
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
    out = s.reverseKGroup(head, 2);
    while (out != NULL){
    	cout << "original val: " << out->val << " address: " << out << " next: " << out->next << endl;
    	out = out->next;
    }  
}
