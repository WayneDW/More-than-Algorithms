#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include "func.cpp"

using namespace std;

/*
Given a string, determine if a permutation of the string could form a palindrome.

For example,
"code" -> False, "aab" -> True, "carerac" -> True.*/

class Solution {
public:
    bool canPermutePalindrome(string s) {
        if (s.empty()) return false;
        int dt[256] = {0};
        for (auto par : s) dt[par - '0'] += 1;
        int tag = 0;
        for (auto &c : dt) {
            if (c % 2 == 1) tag++;
        }
        if (tag > 1) return false;
        if (tag == 1) return s.size() % 2 == 1;
        return true;
    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.canPermutePalindrome("aab") << endl;
}
