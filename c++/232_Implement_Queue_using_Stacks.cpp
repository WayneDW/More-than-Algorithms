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
/*
Implement Queue using Stacks
Implement the following operations of a queue using stacks.

push(x) -- Push element x to the back of queue.
pop() -- Removes the element from in front of queue.
peek() -- Get the front element.
empty() -- Return whether the queue is empty.
Notes:
You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).

*/

class Queue {
stack<int> stk;
public:
    // Push element x to the back of queue.
    void push(int x) {
        stk.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stack<int> que;
        int size = stk.size() - 1;
        for (int i = 0; i < size; i++) {
            que.push(stk.top());
            stk.pop();
        }
        stk.pop();
        while (!que.empty()) {
            stk.push(que.top());
            que.pop();
        }
    }

    // Get the front element.
    int peek(void) {
        stack<int> que;
        int size = stk.size() - 1;
        for (int i = 0; i < size; i++) {
            que.push(stk.top());
            stk.pop();
        }
        int last = stk.top();
        while (!que.empty()) {
            stk.push(que.top());
            que.pop();
        }
        return last;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk.empty();
    }
};


int main() {
	Queue s;
    Examples eg;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.peek() << endl;
}
