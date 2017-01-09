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

The expression string contains only non-negative integers, +, -, *, / operators and 
empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5*/

class Solution {
public:
    int calculate(string s) {
        int res = 0, num = 0, local = 0, sign = 1, last = 0; // last is to indicate if the last signal is * (denoted as 1) or /(-1)
        for (auto c: s) {
            if (isdigit(c)) num = 10 * num + c - '0';
            else if (c == '+') {
                if (last == 1) num *= local;
                else if (last == -1) num = local / num;
                res += num * sign;
                sign = 1;
                last = 0;
                num = 0;
            }
            else if (c == '-') {
                if (last == 1) num *= local;
                else if (last == -1) num = local / num;
                res += num * sign;
                sign = -1;
                last = 0;
                num = 0;
            }
            else if (c == '*') {
                if (last == 1) num *= local;
                else if (last == -1) num = local / num; // don't update res in the inner loop, but rather in +/- or the last part
                local = num; // for case of 1 + 2 * 3, local is like 2; for 1 + 2 * 3 * 5, local is like 2 and 6
                last = 1;
                num = 0;
            }
            else if (c == '/') {
                if (last == 1) num *= local;
                else if (last == -1) num = local / num;
                local = num;
                last = -1;
                num = 0;
            }
        }
        if (num) {
            if (last == 1) num = num * local;
            else if (last == -1) num = local / num;
            res += num * sign;
        }
        return res;
    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.calculate(" 1- 2*3 / 6") << endl;
}
