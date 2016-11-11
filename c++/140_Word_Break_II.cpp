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
        vector<bool> dp(n+1, false);
        dp[0] = true; 
        for (int i = 0; i < n; i++) {
            for (int j = i; j >= 0; j--) {
                if (dp[j] && wordDict.count(s.substr(j, i-j+1)) > 0) {
                    dp[i+1] = true;
                    break; // no need for further steps
                }
            }
        }
        if(dp[n] == false)  return res; // without this line, time limit exceeded
        string subStr = "";
        checkRight(res, s, subStr, 0, n, wordDict, dp);
        return res;
    }
    void checkRight(vector<string>& res, string s, string subStr, // can't be address here, otherwise bug
        int pos, int n, unordered_set<string>& wordDict, vector<bool> &dp) {
        if (pos >= n) {
            subStr.pop_back();
            res.push_back(subStr);
            return;
        }
        string word = "";
        for (int i = pos; i < n; i++) {
            word.push_back(s[i]);
            cout << word << endl;
            if (dp[i+1] && wordDict.count(word) > 0) {
                subStr += word + " ";
                // common mistake is i + 1, here i can already represent length
                checkRight(res, s, subStr, i + 1, n, wordDict, dp); 
                subStr = subStr.substr(0, subStr.size() - word.size() - 1);
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
    string a = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    //print1dVector(s.wordBreak(a, wordDict)); // easily time limit exceeded

}
