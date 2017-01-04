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

/*All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, 
for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify 
repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur 
more than once in a DNA molecule.

For example,

Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",

Return:
["AAAAACCCCC", "CCCCCAAAAA"].*/

class Solution1 { // use 3 bits per letter
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m;
        vector<string> r;
        int t = 0, i = 0, len = s.size();
        // the purpose here is that before we roll to the 9th letter, we can't build the hash map
        while (i < 9) t = t << 3 | s[i++] & 7; // s[i] & 7 helps us 
        while (i < len) {
            if (m[t = t << 3 & 0x3FFFFFFF | s[i++] & 7]++ == 1) // 0x3FFFFFFF means 0011 1111 1111 ....
                r.push_back(s.substr(i - 10, 10));
        }
        return r;
    }
    // updated version
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m;
        vector<string> r;
        // skip the original lines since the first 9 letters won't match any 10-letter key
        for (int t = 0, i = 0; i < s.size(); i++) 
            if (m[t = t << 3 & 0x3FFFFFFF | s[i] & 7]++ == 1)
                r.push_back(s.substr(i - 9, 10));
        return r;
    }

    // even better version
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m;
        vector<string> r;
        for (int t = 0, i = 0; i < s.size(); i++)
            if (m[t = t << 2 & 0xFFFFF | (s[i] - 64) % 5]++ == 1)
                r.push_back(s.substr(i - 9, 10));
        return r;
    }
};


int main() {
    Solution s;
    Examples eg;
    string ss = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    printVector(s.findRepeatedDnaSequences(ss));
}
