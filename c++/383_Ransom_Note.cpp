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

/*Given an arbitrary ransom note string and another string containing letters from 
all the magazines, write a function that will return true if the ransom note can be 
constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true*/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int dp[26] = {0};
        for (auto c: magazine) dp[c - 'a']++;
        for (auto c: ransomNote) if (--dp[c - 'a'] < 0) return false;
        return true;
    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.canConstruct("aa", "aab") << endl;
}
