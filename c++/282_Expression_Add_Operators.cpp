#include <iostream>
#include <vector>
#include <map>
#include <set>
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

/*Given a string that contains only digits 0-9 and a target value, return all possibilities to 
add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Examples: 
"123", 6 -> ["1+2+3", "1*2*3"] 
"232", 8 -> ["2*3+2", "2+3*2"]
"105", 5 -> ["1*0+5","10-5"]
"00", 0 -> ["0+0", "0-0", "0*0"]
"3456237490", 9191 -> []*/


/*overflow: long
string starting with 0
multiplication*/

class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.size() == 0) return res;

        for (int i = 1; i <= num.size(); i++) {
            string sub = num.substr(0, i);
            if (sub[0] == '0' && sub.size() > 1) continue;
            long total = stol(sub);
            dfs(res, num, sub, i, '!', 0, total, target);
        }
        return res;
    }
    void dfs(vector<string>& res, string num, string str, int pos, char last_op, long toBeMulted, long total, int target) {
        if (pos == num.size() && total == target) {
            res.push_back(str);
        }
        else {
            for (int i = 1; i <= num.size() && i + pos <= num.size(); i++) {
                string sub = num.substr(pos, i);
                if (sub[0] == '0' && sub.size() > 1) continue;
                long v = stol(sub);
                dfs(res, num, str + '+' + sub, pos + i, '+', v, total + v, target);
                dfs(res, num, str + '-' + sub, pos + i, '-', -v, total - v, target);
                // take care that we should keep last_op, toBeMulted should not be total * v
                if (last_op == '-' || last_op == '+')
                    dfs(res, num, str + '*' + sub, pos + i, last_op, toBeMulted * v, total - toBeMulted + v * toBeMulted, target);
                else
                    dfs(res, num, str + '*' + sub, pos + i, last_op, toBeMulted * v, total * v, target); 
            }
        }
    }
};

class Solution { // simplified version
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.size() == 0) return res;
        dfs(res, num, "", 0, '!', 0, total, target);
        return res;
    }
    void dfs(vector<string>& res, string num, string str, int pos, char last_op, long toBeMulted, long total, int target) {
        if (pos == num.size() && total == target) {
            res.push_back(str);
        }
        else {
            for (int i = 1; i <= num.size() && i + pos <= num.size(); i++) {
                string sub = num.substr(pos, i);
                if (sub[0] == '0' && sub.size() > 1) continue;
                long v = stol(sub);
                if (pos == 0) dfs(res, num, sub, i, '!', 0, v, target);
                else {
                    dfs(res, num, str + '+' + sub, pos + i, '+', v, total + v, target);
                    dfs(res, num, str + '-' + sub, pos + i, '-', -v, total - v, target);
                    if (last_op == '-' || last_op == '+')
                        dfs(res, num, str + '*' + sub, pos + i, last_op, toBeMulted * v, total - toBeMulted + v * toBeMulted, target);
                    else
                        dfs(res, num, str + '*' + sub, pos + i, last_op, toBeMulted * v, total * v, target); 
                }
            }
        }
    }
};


int main() {
    Solution s;
    Examples eg;
    string num = "123456789";
    print(s.addOperators(num, 45));
}
