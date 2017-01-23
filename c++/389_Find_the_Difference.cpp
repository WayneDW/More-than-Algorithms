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

/*Given two strings s and t which consist of only lowercase letters.

String t is generated by random shuffling string s and then add one more letter at a random position.

Find the letter that was added in t.

Example:

Input:
s = "abcd"
t = "abcde"

Output:
e

Explanation:
'e' is the letter that was added.*/

// class Solution {
// public:
//     char findTheDifference(string s, string t) {
//         char diff = 0;
//         int cnt[256] = {0};
//         for (char c : s) cnt[c]++;
//         for (char c : t) if (--cnt[c] < 0) return c;
//         return 0;
//     }
// };

class Solution_hash {
public:
    char findTheDifference(string s, string t) {
        unordered_map<int, int> mp;
        for (auto c: s) mp[c]++;
        for (auto c: t) mp[c]--;
        for (auto n: mp) {
            if (n.second < 0) return n.first;
        }
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = 0;
        for (auto c: s) res ^= c;
        for (auto c: t) res ^= c;
        return res;
    }
};

int main() {
    Solution s;
    Examples eg;
    cout << s.findTheDifference("abcd", "abcde") << endl;
}
