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

/*Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

For example,
Given "egg", "add", return true.

Given "foo", "bar", return false.

Given "paper", "title", return true.*/


class Solution {
public:
    bool isIsomorphic_failed(string s, string t) {
        int dt1[256] = {0}, dt2[256] = {0};
        for (int i = 0; i < s.size(); i++) {
            dt1[s[i]]++, dt2[t[i]]++;
            if (dt1[s[i]] != dt2[t[i]]) return false; // this case fails when s="aba" t="baa"
        }
        return true;
    }

    bool isIsomorphic(string s, string t) {
        int dt1[256] = {0}, dt2[256] = {0};
        for (int i = 0; i < s.size(); i++) {
            if (dt1[s[i]] != dt2[t[i]]) return false;
            dt1[s[i]] = i + 1; // without + 1, it fails in the case of "aa", "ab"
            dt2[t[i]] = i + 1;
        }
        return true;
    }
};

int main() {
    Solution s;
    Examples eg;
    cout << s.isIsomorphic("egg", "add") << endl;
}
