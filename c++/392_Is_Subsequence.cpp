#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
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

/*Given a string s and a string t, check if s is subsequence of t.

You may assume that there is only lower case English letters in both s and t. t is potentially a very 
long (length ~= 500,000) string, and s is a short string (<=100).

A subsequence of a string is a new string which is formed from the original string by deleting some 
(can be none) of the characters without disturbing the relative positions of the remaining characters. 
(ie, "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:
s = "abc", t = "ahbgdc"

Return true.

Example 2:
s = "axc", t = "ahbgdc"

Return false.

Follow up:
If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one 
to see if T has its subsequence. In this scenario, how would you change your code?*/

/*class Solution { // Memory Limit Exceeded
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        if (s.size() > 0 && t.size() == 0) return false;

        if (s[0] == t[0]) return isSubsequence(s.substr(1), t.substr(1));
        else return isSubsequence(s, t.substr(1));
    }
};*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0) return true;
        for (int i = 0; i < t.size(); i++) {
            if (s[0] == t[i])  // a good trick
                return isSubsequence(s.substr(1), t.substr(i+1));
        }
        return false;
    }
};

/* binary search for follow up 
   save the idx of every charactor of t
   use binary search to find the postition of a certain character in t, this speeds up finding the right matched chararacter
*/



int main() {
    Solution s;
    Examples eg;
    cout << s.isSubsequence("axc", "ahbgdc") << endl;
}
