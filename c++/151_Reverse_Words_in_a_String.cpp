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

class Solution2 { // although not so efficient, still don't know why buged
public:
    void reverseWords(string &s) {
        if (!s.size()) return;
        string wd, res;
        for (int i = 0; i < s.size(); i++) {
            if (!isspace(s[i]))
                wd.push_back(s[i]);
            else if (wd.size() > 0) {
                res.append(wd + ' ');
                wd.clear();
            }
        }
        if (!res.empty()) res.pop_back();
        int n = res.size();
        int start = 0, len = 0;
        reverse(res, 0, n);
        for (int i = 0; i <= n; i++) {
            if (i < n && res[i] != ' ') len++;
            else if (len > 0) {
                reverse(res, start, len);
                start = i + 1; len = 0;
            }
        }
        s = res;
    }
    void reverse(string &s, int l, int len) {
        if (!s.size()) return;
        for (int i = 0; i < (len + 1) / 2; i++) {
            char tmp = s[l + len - 1 - i];
            s[l + len - 1 - i] = s[i + l];
            s[i + l] = tmp;
        }
    }
};

class Solution {
public:
    void reverseWords(string &s) {
        int j;
        string res;
        for (int i = s.size() - 1; i > -1; i--) {
            if (isspace(s[i]))
                j = i;
            else if (i == 0 || isspace(s[i - 1])){
                if (res.size() > 0) res.push_back(' ');
                res.append(s.substr(i, j - i));
            }
        }
        s = res;
    }
};

int main() {
	Solution2 s;
    Examples eg;
    string ss = " as   abc    ";
    s.reverseWords(ss);
    cout << ss << "|" << endl;
}
