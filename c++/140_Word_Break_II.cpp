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

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<string> res;
        if (!n) return res;
        //vector<vector<bool> > dp(n+1, vector<bool>(n+1, false));
        vector<bool> dp(n+1, false);
        dp[0] = true;
        checkRight(res, s, "", 0, n, wordDict, dp);
        //print1dVector(dp);
        return res;
    }
    void checkRight(vector<string>& res, string s, string subStr, 
        int pos, int n, unordered_set<string>& wordDict, vector<bool> &dp) {
        if (pos >= n) {
            subStr.pop_back();
            res.push_back(subStr);
            return;
        }
        for (int i = pos; i < n; i++) {
            for (int len = 1; len <= n - i; len++) {
                string sub = s.substr(i, len);
                if (dp[i] && wordDict.count(sub) > 0) {
                    dp[i+len] = true;
                    subStr += sub + "_";
                    checkRight(res, s, subStr, i+len, n, wordDict, dp);
                    subStr = subStr.substr(0, subStr.size() - sub.size() - 1);
                    dp[i+len] = false;
                }
            }
        }

        
    }
};


int main() {
	Solution s;
    Examples eg;
    unordered_set<string> wordDict;
    wordDict.insert("cat");
    wordDict.insert("cats");
    wordDict.insert("and");
    wordDict.insert("sand");
    wordDict.insert("dog");
    wordDict.insert("a");
    wordDict.insert("aa");
    wordDict.insert("aaa");
    wordDict.insert("aaaa");
    wordDict.insert("aaaaa");
    wordDict.insert("aaaaaa");
    wordDict.insert("aaaaaaa");
    wordDict.insert("aaaaaaaa");
    wordDict.insert("aaaaaaaaa");
    print1dVector(s.wordBreak("catsanddog", wordDict));
    print1dVector(s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", wordDict));

}
