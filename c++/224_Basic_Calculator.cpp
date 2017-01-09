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

/*Implement a basic calculator to evaluate a simple expression string.

The expression string may contain (), +, -, non-negative integers and empty spaces .

You may assume that the given expression is always valid.

Some examples:
"1 + 1" = 2
" 2-1 + 2 " = 3
"(1+(4+5+2)-3)+(6+8)" = 23
Note: Do not use the eval built-in library function.*/

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int result = 0, num = 0, sign = 1;
        for (auto c: s) {
            if (isdigit(c)) {
                num = 10 * num + c - '0';
            }
            else if (c == '+') {
                result += num * sign;
                sign = 1;
                num = 0;
            }
            else if (c == '-') {
                result += num * sign;
                sign = -1;
                num = 0;
            }
            else if (c == '(') {
                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
                //num = 0;  work without it, since there must be + or - before (, thus num is already set to 0
            }
            else if (c == ')') {
                result += num * sign; // useful in cases like 1-(5)
                num = 0;
                result *= stk.top(); stk.pop();
                result += stk.top(); stk.pop();
            }
        }
        if (num) result += num * sign;
        return result;
    }
};

int main() {
    Solution s;
    Examples eg;
    cout << s.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    cout << s.calculate("2147483647") << endl;
    cout << s.calculate("1-(5)") << endl;
}
