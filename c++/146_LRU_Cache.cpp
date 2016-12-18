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

class LRUCache{
    struct Node {
        int key;
        int val;
        Node* prev, *next;
        Node(int k, int v): key(k), val(v), prev(NULL), next(NULL) {} // constructor, no semicolon
    };

    void removeNodeHead() {
        if (dt.empty()) return;
        dt.erase(head->key);
        if (head == tail)
            head = tail = NULL;
        else {
            head = head->next;
            head->prev = NULL;
        }
    }

    void insertNodeTail(int k, int v) {
        Node* nd = new Node(k, v);
        dt[k] = nd;
        if (!head)
            head = tail = nd;
        else {
            tail->next = nd;
            nd->prev = tail;
            tail = tail->next;
        }
    }

    void moveToEnd(int key) { // move the key to the mostly recent used location/ end
        if (dt[key] == tail) return; // do nothing if it is already in the tail
        Node* nd = dt[key];
        if (nd == head) { // if key in the head
            head = head->next;
            head->prev = NULL;
        }
        else { // if key not in the tail nor head
            nd->prev->next = nd->next;
            nd->next->prev = nd->prev;
        }
        tail->next = nd;
        nd->prev = tail;
        tail = tail->next;
    }

    int maxSize;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> dt;

public:
    LRUCache(int capacity) {
        maxSize = capacity;
        dt.clear();
    }
    
    int get(int key) {
        if (dt.count(key) == 0) return -1;
        moveToEnd(key); // move the key to the end of list due to usage
        return dt[key]->val;  
    }

    void set(int key, int val) {
        if (dt.count(key) > 0) {
            moveToEnd(key);
            dt[key]->val = val;
            return;
        }
        if (dt.size() == maxSize) removeNodeHead(); // remove the least used node
        insertNodeTail(key, val);
    }

};


int main() {
    Solution s;
    Examples eg;
}
