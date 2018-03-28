#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include "func.cpp"

using namespace std;

/*138. Copy List with Random Pointer   QuestionEditorial Solution  My Submissions

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.*/



struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


/*  Suppose there is one such list l1 with nodes A, B and C
    on the next pointer, A->B->C, on the random part, A->C, B->A, C->B

    Step 1, change the next pointer to: A->E->B->F->C->G

    Step 2, add random pointer to E, F, G as the following forms
            E->random = A->random->next, then A = A->next->next, F->random = B->random,...

    Step 3, break the two linklist into two parts, so that A->next = B 
*/
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return head;
        RandomListNode *l1, *l2;

        for (l1 = head; l1; l1 = l1->next->next) { // nice struture
            RandomListNode *tmp = new RandomListNode(l1->label);
            tmp->next = l1->next; // step 1, E->B
            l1->next = tmp; // step1, A->E
            if (l1 == head) l2 = tmp;
        }

        for (l1 = head; l1; l1 = l1->next->next) {
            if (l1->random != NULL) l1->next->random = l1->random->next; // next after random (random->next) is to use G rather than C
        }

        for (l1 = head; l1; l1 = l1->next) {
            RandomListNode *tmp = l1->next->next;
            if (tmp) l1->next->next = tmp->next;
            l1->next = tmp;
        }
        return l2;
    }
};


int main() {
    Solution s;
    Examples eg;
    RandomListNode* A = new RandomListNode(1);
    RandomListNode* B = new RandomListNode(2);
    RandomListNode* C = new RandomListNode(3);
    A->next = B;
    A->random = C;
    B->next = C;
    B->random = A;
    C->random = B;
    RandomListNode* res = s.copyRandomList(A);
    cout << res->label << endl;
    
}
