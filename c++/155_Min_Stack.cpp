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
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2*/

class MinStack {
    stack<int> dat;
    stack<int> minDat;
public:
    // MinStack() {
    //     dat.clear(); // stack has no clear
    //     minDat.clear();
    // }
    
    void push(int x) {
        if (minDat.empty() || minDat.top() >= x)
            minDat.push(x);
        dat.push(x);
    }
    
    void pop() {
        if (dat.empty()) return;
        if (minDat.top() == dat.top())
            minDat.pop();
        dat.pop();
    }
    
    int top() {
        return dat.top();
    }
    
    int getMin() {
        return minDat.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */


int main() {
    Solution s;
    Examples eg;
}
