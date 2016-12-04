#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/*
	Use two pointers to reach the middle point
	then reverse linked list, the fast pointer keeps going, 
	the slow return the opposite direction

*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
    	if(!head || !head->next)
            return true;
    	auto slow = head, fast = head;
    	while (fast->next && fast->next->next) {
    		slow = slow->next;
    		fast = fast->next->next;
    	}
    	slow = reverseLinkedList(slow->next);
    	while (slow) {
    		if (slow->val != head->val) return false;
    		slow = slow->next;
    		head = head->next;
    	}
    	return true;
    }

    ListNode* reverseLinkedList(ListNode* head) {
    	ListNode *next = NULL;
    	ListNode *prev = NULL;
    	while (head) {
    		next = head->next;
    		head->next = prev;
    		prev = head;
    		head = next;
    	}
    	return prev;
    }
};


int main() {
    Solution s;
    Examples eg;
}
