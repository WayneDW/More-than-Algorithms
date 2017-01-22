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

/*Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear
 once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example:
Given "bcabc"
Return "abc"

Given "cbacdcbc"
Return "acdb"*/

/*Smallest in lexicographical order: for simplicity, you can understand the lexicographical order as the order used in a dictionary.
a < aa < aaa < ab < abb < abc < b < bcd < be < ...*/


/*stack version, push every character into stack
if the next one is smaller than the top char of the stack (and that one appears multiple times), pop it, we can add it later*/

class Solution { 
public:
    string removeDuplicateLetters(string s) {
        int cnt[26] = {0};
        bool visited[26] = {false};
        for (auto c: s) cnt[c - 'a']++;
        stack<char> stk; // we keep every character only once
        for (auto c: s) {
            cnt[c - 'a']--;
            if (visited[c - 'a']) continue; // keep the first one when 2 same characters appears, e.g. acbade
            while (!stk.empty() && c < stk.top() && cnt[stk.top() - 'a'] > 0) {
                visited[stk.top() - 'a'] = false;
                stk.pop();
            }
            stk.push(c);
            visited[c - 'a'] = true;
        }
        string res = "";
        while (!stk.empty()) {
            res = stk.top() + res;
            stk.pop();
        }
        return res;
    }
};

int main() {
    Solution s;
    Examples eg;
    cout << s.removeDuplicateLetters("cbacdcbc") << endl;
}
