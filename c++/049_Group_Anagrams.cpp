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
#include "000_basic.cpp"

/*
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]*/

class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > dt;

        for (int i = 0; i < strs.size(); i++) {
            string sortedWord = strs[i];
            sort(sortedWord.begin(), sortedWord.end());
            dt[sortedWord].push_back(strs[i]); // every key has a vector<string>
        }

        vector<vector<string> > res;
        for (map<string, vector<string> >::iterator it = dt.begin(); it != dt.end(); it++) {
            res.push_back(it->second); // just take the values
        }
        return res;
    }
};

class Solution3 { // incomplete version, but easy idea
    static bool cmp(pair<string, string> p1, pair<string, string> p2) {
        return p1.second < p2.second;
    }
public:
    void groupAnagrams(vector<string>& strs) {
        vector<pair<string, string> > pstrs;
        vector<string> strsBak = strs;
        for (int i = 0; i < strs.size(); i++) {
            sort(strsBak[i].begin(), strsBak[i].end());
            pair<string, string> pr(strs[i], strsBak[i]);
            pstrs.push_back(pr);
        }
        sort(pstrs.begin(), pstrs.end(), cmp);
        for (int i = 0; i < pstrs.size(); i++) {
            cout << pstrs[i].first << " " << pstrs[i].second << endl;
        }
    }
};
/*
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]*/

class Solution3 {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string, int> ht;
        int num = 0;
        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (ht.count(tmp) == 0) {
                ht[tmp] = num++;
                vector<string> line;
                line.push_back(strs[i]);
                res.push_back(line);
            }
            else {
                res[ht[tmp]].push_back(strs[i]);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    string ss[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> vecS(ss, ss + 6);
    vector<vector<string> > res;
    res = s.groupAnagrams(vecS);
    printVector(res);
}
