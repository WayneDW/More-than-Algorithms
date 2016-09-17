#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if (m == n)
    		return head;
    	ListNode *p = new ListNode(0);
    	p->next = head;
    	head = p;
    	ListNode *left = p, *right = p;
    	for (int i = 0; i < m; i++) {
    		left = left->next;
    		if (i != m - 1)
    			p = p->next;
    	}
    	for (int i = 0; i < n; i++)
    		right = right->next;
    	p->next = right;
    	right = right->next;

    	for (int i = n - m; i > 0; i--) {
    		ListNode *tmp = left;
    		for (int j = i - 1; j > 0; j--)
    			tmp = tmp->next;
    		tmp->next->next = tmp;
    	}
    	left->next = right;
    	return head->next;   
    }
};


int main() {
	Solution s;
}