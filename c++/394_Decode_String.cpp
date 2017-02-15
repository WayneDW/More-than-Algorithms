#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

/*Given an encoded string, return it's decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. 
Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. 
For example, there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".*/

class Solution_to_slow {
public:
    string decodeString(string s) {
        stack<int> digits;
        stack<char> chars;
        int sum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) sum = 10 * sum + s[i] - '0';
            else if (s[i] == '[') {
                digits.push(sum);
                sum = 0;
                chars.push(s[i]);  
            }
            else if (isalpha(s[i])) chars.push(s[i]); 
            else if (s[i] == ']') {
                int len = digits.top(); digits.pop();
                string part = "";
                while (!chars.empty() && chars.top() != '[') {
                    part = chars.top() + part;
                    chars.pop();
                }
                string combi = "";
                while (len--) combi += part;
                chars.pop(); // pop '[' 
                for (auto c: combi) chars.push(c); // push cc 
            }
        }
        string res = "";
        while (!chars.empty()) {
            res = chars.top() + res;
            chars.pop();
        }
        return res;
    }
};


class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return dfs(s, i);
    }

    string dfs(string s, int &i) {
        string res = "";
        while (i < s.size() && s[i] != ']') {
            if (isdigit(s[i])) {
                int sum = 0;
                while (isdigit(s[i])) sum = 10 * sum + s[i++] - '0'; // skip the numbers and end up at location [
                i++; // skip [
                string part = dfs(s, i);
                i++; // skip ]
                while (sum--) res += part;
            }
            else if (isalpha(s[i])) res += s[i++];
        }
        return res;
    }
};



int main() {
    Solution s;
    Examples eg;
    string ss = "3[a2[c]]";
    cout << s.decodeString(ss) << endl; 
}
