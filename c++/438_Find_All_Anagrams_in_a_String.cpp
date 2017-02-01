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

/*Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".*/


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        vector<int> dp(26, 0);
        unordered_map<char, int> mp;
        for (auto c: p) mp[c]++;

        for (int i = 0; i < s.size(); i++) {
            dp[s[i] - 'a']++;
            if (i >= p.size() - 1) {
                if (i >= p.size()) dp[s[i - p.size()] - 'a']--; // check i is important
                if (cmp(mp, dp)) res.push_back(i - p.size() + 1);
            }
        }
        return res;
    }
    bool cmp(unordered_map<char, int> mp, vector<int> dp) { // another way to compare is to create 2 vector, and just compare
        for (auto c: mp) if (c.second != dp[c.first - 'a']) return false;
        return true;
    }
};


int main() {
    Solution s;
    Examples eg;
    print(s.findAnagrams("cbaebabacd", "abc"));
    print(s.findAnagrams("abab", "ab"));
}
