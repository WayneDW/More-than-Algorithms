#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

/*Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6*/


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stk;
        unordered_set<string> set;
        set.insert("+");
        set.insert("-");
        set.insert("*");
        set.insert("/");
        for (auto token : tokens) {
            //cout << token << endl;
            if (set.count(token) == 0)
                stk.push(token);
            else {
                int a = stoi(stk.top()); stk.pop();
                int b = stoi(stk.top()); stk.pop();
                int c = operation(b, a, token);
                stk.push(to_string(c));
            }
        }
        return stoi(stk.top());
    }
    int operation(int a, int b, string c) {
        if (c == "+") return a + b;
        if (c == "*") return a * b;
        if (c == "-") return a - b;
        if (c == "/") return a / b;
        return 0;
    }
};


int main() {
    Solution s;
    Examples eg;
    string ss[] = {"2", "1", "+", "3", "*"};
    vector<string> vec(ss, ss + 5);
    cout << s.evalRPN(vec) << endl;
}
