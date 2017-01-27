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

/*Given a string array words, find the maximum value of length(word[i]) * length(word[j]) 
where the two words do not share common letters. You may assume that each word will contain 
only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxP = 0;
        vector<bitset<26>> vec(words.size());
        for (int i = 0; i < words.size(); i++) {
            for (auto c: words[i]) vec[i].set(c - 'a', 1); // another way is to use int i |= 1 << (c - 'a');
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if ((vec[i] & vec[j]) == 0)
                    maxP = max(maxP, int(words[i].size() * words[j].size()));
            }
        }
        return maxP;
    }
};



int main() {
    Solution s;
    Examples eg;
    vector<string> vec = {"eae","ea","aaf","bda","fcf","dc","ac","ce","cefde","dabae"};
    cout << s.maxProduct(vec) << endl;
}
