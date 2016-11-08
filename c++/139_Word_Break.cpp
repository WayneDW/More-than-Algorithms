#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include "func.cpp"

using namespace std;

/*Given a string s and a dictionary of words dict, determine if s can be segmented into 
a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".*/

class Solution_slow_version {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<vector<string> > res;
        vector<string> line;
        dfs(s, 0, line, res, wordDict);
        return res.size() > 0;
    }
    void dfs(string s, int start, vector<string> line, vector<vector<string> > &res, unordered_set<string>& wordDict) {
        if (start >= s.size()) {
            res.push_back(line);
            return;
        }
        for (int i = 1; i + start <= s.size(); i++) {
            string sub = s.substr(start, i);
            if (wordDict.count(sub) > 0) {
                line.push_back(sub);
                dfs(s, start + i, line, res, wordDict);
                line.pop_back();
            }
        }
    }
};

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        if (n == 0) return false;
        vector<bool> dp(n + 1, false); // dp[i+1] : 0~i is trues
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (dp[j] && wordDict.count(s.substr(j, i-j+1)) > 0) {
                    dp[i+1] = true;
                    break; // no need for further steps
                }
            }
        }
        return dp[n];
    }
};


int main() {
	Solution s;
    Examples eg;
    unordered_set<string> wordDict;
    wordDict.insert("leet");
    wordDict.insert("code");
    cout << s.wordBreak("leetcode", wordDict) << endl;
}
