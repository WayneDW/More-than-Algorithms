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

/*Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.*/

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, int> idt;
        unordered_map<int, string> dt;
        stringstream is(str);
        string word;
        for (int i = 0; i < pattern.size(); i++) {
            int key = pattern[i] - 'a';
            is >> word;
            if (idt.count(word) == 0) idt[word] = key;
            else if (idt[word] != key) return false;
            if (dt.count(key) == 0) dt[key] = word;
            else if (dt[key] != word) return false;
        }
        int tag = -1;
        while (is) { // weird that is will print dog cat cat fish fish
            is >> word;
            tag += 1;
        }
        return tag == 1? false: true;
    }
};




int main() {
    Solution s;
    Examples eg;
    cout << s.wordPattern("abba", "dog cat cat fish") << endl;
}
