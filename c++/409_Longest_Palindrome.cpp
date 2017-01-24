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

/*Given a string which consists of lowercase or uppercase letters, find the length of the 
longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.*/

class Solution {
public:
    int longestPalindrome(string s) {
        int dp[256] = {0};
        for (auto c: s) dp[c - 'A']++;
        int res = 0, maxOdd = 0;
        for (auto c: dp) {
            if (c % 2 == 0) res += c;
            else maxOdd += (maxOdd == 0? c: c - 1); // keep one odd number, but delete others, instead, we keep even number of them
        }
        return res + maxOdd;
    }
};

int main() {
    Solution s;
    Examples eg;
    cout << s.longestPalindrome("abccccdd") << endl;
}
