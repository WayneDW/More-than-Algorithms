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

/*Find the length of the longest substring T of a given string (consists of lowercase 
letters only) such that every character in T appears no less than k times.

Example 1:

Input:
s = "aaabb", k = 3

Output:
3

The longest substring is "aaa", as 'a' is repeated 3 times.
Example 2:

Input:
s = "ababbc", k = 2

Output:
5

The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is repeated 3 times.*/

class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() < k || s.size() == 0) return 0;
        if (k == 0) return s.size();
        int dp[26] = {0};
        for (auto c: s) dp[c - 'a']++;

        int ik = 0;
        while (ik < s.size() && dp[s[ik] - 'a'] < k) ik++; // trick: time blows up from 3 to 100+ms without it
        if (ik == s.size()) return 0;
        int idx = ik;
        while (idx < s.size() && dp[s[idx] - 'a'] >= k) idx++;
        if (idx == s.size()) return idx - ik;

        int left = longestSubstring(s.substr(ik, idx), k);
        int right = longestSubstring(s.substr(idx + 1), k);
        return max(left, right);
    }
};



int main() {
    Solution s;
    Examples eg;
}
