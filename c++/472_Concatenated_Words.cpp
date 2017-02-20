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

/*Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.

A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.

Example:
Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]

Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]

Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats"; 
 "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; 
"ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
Note:
The number of elements of the given array will not exceed 10,000
The length sum of elements in the given array will not exceed 600,000.
All the input string will only include lower case letters.
The returned elements order does not matter.*/


class Solution_TLE {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        for (int i = 0; i < words.size(); i++) {
            dfs(words, words[i], 0, st);
        }
        return res;
    }

    void dfs(vector<string>& words, string word, int i, unordered_set<string> st) {
        if (i > word.size()) return;
        if (i == word.size()) {
            if (solution.find(word) != solution.end()) return;
            if (word != "") res.push_back(word);
            solution.insert(word);
            return;
        }
        for (int len = 1; len <= word.size() - i; len++) { 
            if (st.count(word.substr(i, len)) > 0 && len != word.size()) {
                dfs(words, word, i + len, st);
            }
        }
    }
private:
    unordered_set<string> solution; // to avoid duplicate solution
    vector<string> res;
};

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(), words.end());
        vector<string> res;
        for (auto w : words) {
            int n = w.size();
            vector<bool> dp(n + 1, false); // dp[i] = 1 represents string 0~i matches some word
            dp[0] = true; 
            for (int i = 0; i < n; i++) {
                if (!dp[i]) continue;
                for (int len = 1; len <= n - i; len++) {
                    if (len != n && st.count(w.substr(i, len)) > 0) dp[i + len] = true;
                }
                if (dp[n]) { res.push_back(w); break;}
            }
            // if (dp[n]) res.push_back(w); // this line can't handle [""] case, since it could add w="" into res
        }
        return res;
    }
};



int main() {
    Solution s;
    Examples eg;
    vector<string> words = {"cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat", "catsdogcats"};
    print(s.findAllConcatenatedWordsInADict(words));
}
