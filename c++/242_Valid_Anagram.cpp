#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

class Solution {
public:
    bool isAnagram1(string s, string t) { // 76 ms
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }

    bool isAnagram2(string s, string t) { // 36 ms
        unordered_map<char, int> dt;
        for (auto c: s) {
            dt[c] += 1;
        }
        for (auto c: t) {
            dt[c] -= 1;
        }

        for (auto it: dt) {
            if (it.second != 0) return false;
        }
        return true;
    }

    bool isAnagram(string s, string t) { // 12 ms
        int dt[26] = {0};
        for (auto c: s) {
            dt[c - 'a'] += 1;
        }
        for (auto c: t) {
            dt[c - 'a'] -= 1;
        }

        for (int i = 0; i < 26; i++) {
            if (dt[i] != 0) return false;
        }
        
        return true;
    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.isAnagram("abc", "cab") << endl;
}
