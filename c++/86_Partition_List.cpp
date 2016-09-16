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

// 3-min written version
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *lt = new ListNode(0);
        ListNode *ge = new ListNode(0);
        ListNode *geHead = ge, *ltHead = lt;
        while (head) {
        	ListNode *tmp = new ListNode(head->val);
        	if (head->val < x) {
        		lt->next = tmp;
        		lt = lt->next;
        	}
        	else {
        		ge->next = tmp;
        		ge = ge->next;
        	}
        	head = head->next;
        }
        lt->next = geHead->next;
        return ltHead->next;
       
    }
};


class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode *lt = new ListNode(0);
        ListNode *ge = new ListNode(0);
        ListNode *geHead = ge;
        lt->next = head;
        head = lt;

        while (head->next) {
        	if (head->next->val < x)
        		head = head->next;
        	else {
        		ge->next = head->next;
        		head->next = head->next->next;
        		ge = ge->next;
        		ge->next = NULL;
        	}
        }
        head->next = geHead->next;
        head = lt->next;
        delete lt, geHead;
        return head;
	}
};
