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

/*Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]*/


/*instead of validating parentheses using stack, we use counter to numerate the number of left and right and pair
through leftmost to the right, the left and right should be equal, and pair should also match.*/

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        unordered_set<string> res;
        for (auto c: s) {
            if (c == '(') left++;
            else if (c == ')') {
                if (left > 0) left--;
                else right++;
            }
        }
        dfs(res, s, "", 0, left, right, 0);
        return vector<string>(res.begin(), res.end());
    }

    void dfs(unordered_set<string> &res, string s, string line, int pos, int left, int right, int pair) {
        if (pos == s.size()) { // the two conditions can't combine together, we need stop when pos == s.size()
            if (left == 0 && right == 0 && pair == 0) res.insert(line);
            return;
        }
        if (s[pos] == '(') {
            if (left > 0) dfs(res, s, line, pos + 1, left - 1, right, pair); // to skip (
            dfs(res, s, line + '(', pos + 1, left, right, pair + 1); // maintain this (
        }
        else if (s[pos] == ')') {
            if (right > 0) dfs(res, s, line, pos + 1, left, right - 1, pair); // to skip )
            // check condition of pair is extremely important
            if (pair > 0) dfs(res, s, line + ')', pos + 1, left, right, pair - 1); // maintain this )
        }
        else dfs(res, s, line + s[pos], pos + 1, left, right, pair);
    }
};


int main() {
    Solution s;
    Examples eg;
    string ss = "(a)())()";
    print(s.removeInvalidParentheses(ss));
}
