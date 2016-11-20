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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if (lists.size() == 0)
    		return NULL;
    	int left, right = lists.size() - 1;
    	while (right > 0) {
    		left = 0;
    		while (left < right)
    			lists[left] = two_merge(lists[left++], lists[right--]);
    	}
    	return lists[0];
    }

    ListNode* two_merge(ListNode *a, ListNode *b) {
    	ListNode *head = new ListNode(0);
    	ListNode *out = head;
    	while (a && b) {
    		if (a->val < b->val) {
    			out->next = a;
    			a = a->next;
    		}
    		else {
    			out ->next = b;
    			b = b->next;
    		}
    		out = out->next;
    	}
    	out->next = a ? a : b;
    	return head->next;
    }
};

int main() {
    Solution s;
    vector<string> ss;
}
