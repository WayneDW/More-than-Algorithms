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

/*Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
Return
  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]*/



// very tricky question, I didn't work this out.
class Solution {
public:
    unordered_map<string, vector<string> > mp; // a map indicating a word's previous word list
    vector<vector<string> > res;
    vector<string> path;
     
    void output(string &start, string last) {
        if (last == start) {
            // vector<string> t(path.rbegin(), path.rend());
            // res.push_back(t);
            reverse(path.begin(), path.end());
            res.push_back(path);
            reverse(path.begin(), path.end());
        }
        else {
            // backtracing to get path recursively
            for (int i = 0; i < mp[last].size(); ++i) {
                path.push_back(mp[last][i]);
                output(start, mp[last][i]);
                path.pop_back();
            }
        }
    }

    void findNext(string str, unordered_set<string> &dict, unordered_set<string> &next_lev) {
        for (int i = 0; i < str.size(); ++i) {
            string s = str;
            for (char j = 'a'; j <= 'z'; ++j) {
                s[i] = j;
                if (dict.count(s)) {
                    next_lev.insert(s);
                    mp[s].push_back(str);
                }
            }
        }
    }

    vector<vector<string> > findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_set<string> cur_lev;
        cur_lev.insert(start);
        unordered_set<string> next_lev;
        path.push_back(end);
         
        // expand to get all the next level valid words
        while (true) {
            for (auto it = cur_lev.begin(); it != cur_lev.end(); it++)
                dict.erase(*it); //delete previous level words from dict to avoid the cycle
             
            for (auto it = cur_lev.begin(); it != cur_lev.end(); it++)
                findNext(*it, dict, next_lev); //find current level words
             
            if (next_lev.empty()) return res;
            
            if (next_lev.count(end)) { //if find end string
                output(start, end);
                return res;
            }
            
            cur_lev = next_lev;
            next_lev.clear();
        }
        
        return res;    
    }
};

int main() {
    Solution s;
    Examples eg;
}
