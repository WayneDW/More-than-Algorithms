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

/*Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".*/

class Solution {
public:
    string reverseVowels(string s) {
        static unordered_set<char> st{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        stack<char> stk;
        queue<int> pos;
        for (int i = 0; i < s.size(); i++) {
            if (st.count(s[i]) > 0) {
                stk.push(s[i]);
                pos.push(i);
            }
        }
        for (int i = 0; i < s.size(); i++) {
            if (!pos.empty() && i == pos.front()) {
                s[i] = stk.top();
                stk.pop(); pos.pop();
            }
        }
        return s;
    }
};

class Solution { // faster solution
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            i = s.find_first_of("aeiouAEIOU", i);
            j = s.find_last_of("aeiouAEIOU", j);
            if (i < j) {
                swap(s[i++], s[j--]);
            }
        }
        return s;
    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.reverseVowels("ai") << endl;
}
