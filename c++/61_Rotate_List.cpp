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
    ListNode* rotateRight(ListNode* head, int k) {
    	if (!head)
    		return head;
        int n = 0;
        ListNode *p = head;
        ListNode *q = head;
        while (p) {
            n += 1;
            if (p->next)
                p = p->next;
            else   
                break;
        }
        if (k == n)
        	return head;
        else
    		p->next = head;
    	k = k % n; // little trick
        for (int i = 1; i < n - k; i++)
            q = q->next;
        head = q->next;
        q->next = NULL;
        return head;
    }
};


int main() {
    Solution s;
    Insert(1, 1);
	Insert(2, 2);
	//Insert(3, 3);
	//Insert(4, 4);
	//Insert(5, 5);
	ListNode *tmp = head;
    while (tmp != NULL){
    	cout << "original val: " << tmp->val << " address: " << tmp << " next: " << tmp->next << endl;
    	tmp = tmp->next;
    }
    ListNode *out = new ListNode(0);
    out = s.rotateRight(head, 3);
    cout << "? " << cout << endl;
    while (out != NULL){
    	cout << "modified val: " << out->val << " address: " << out << " next: " << out->next << endl;
    	out = out->next;
    }

}