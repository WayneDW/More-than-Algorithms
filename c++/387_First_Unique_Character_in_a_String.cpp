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

class Solution_slow {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        if (!n) return -1;
        unordered_map<char, int> dt;
        for (int i = 0; i < n; i++) {
            if (dt.count(s[i]) == 0)
                dt[s[i]] = 1;
            else
                dt[s[i]]++;
        }
        for (int i = 0; i < n; i++) {
            if (dt[s[i]] == 1)
                return i;
        }
        return -1;        
    }
};


class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.size();
        if (!n) return -1;
        int dt[26] = {0};
        for (int i = 0; i < n; i++)
            dt[s[i] - 'a']++;
        for (int i = 0; i < n; i++) {
            if (dt[s[i] - 'a'] == 1)
                return i;
        }
    }
};

int main() {
    Solution s;
    Examples eg;
}
