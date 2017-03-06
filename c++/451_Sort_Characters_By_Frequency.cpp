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

/*Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        for (auto c: s) mp[c]++;

        vector<string> bucket(s.size() + 1);
        for (auto c: mp) {
            char alphabet = c.first;
            int cnt = c.second;
            bucket[cnt].push_back(alphabet);
        }

        string res = "";
        for (int i = s.size(); i >= 0; i--) {
            for (int j = 0; j < bucket[i].size(); j++) {
                int loop = i;
                while (loop--)
                    res += bucket[i][j];
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.frequencySort("aaabbddddddeeeeff") << endl;
}
