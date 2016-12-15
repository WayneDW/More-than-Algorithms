#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include "func.cpp"

using namespace std;



/*
string = abacccaba

iterate location L from 0 to n-1
    iterate len from 1 to n
        check if substr(L, len) is valid
            if so:
                element push back a value
                go into the recursion
                pop back the lasst value
*/

class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > res;
        if (s.size() == 0) return res;
        vector<string> ele;
        dfs(s, 0, ele, res);
        return res;
    }
    bool isPalin(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
    void dfs(string s, int depth, vector<string> &ele, vector<vector<string> > &res) {
        if (depth == s.size()) res.push_back(ele);
        else {
            for (int len = 0; len < s.size() - depth; len++) {
                string sub = s.substr(depth, len + 1);
                if (isPalin(sub)) {
                    ele.push_back(sub);
                    int loc = len + 1 + depth;
                    dfs(s, loc, ele, res);
                    ele.pop_back(); // take care
                }
            }
        }
    }
};


int main() {
	Solution s;
    Examples eg;
    vector<vector<string> > res = s.partition("aaa");
    print2dVector(res);
}
