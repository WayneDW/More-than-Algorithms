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

using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> set;
        unordered_set<string> path; // keep track of the previousu trace to reduce repeating
        for (auto ss: bank) set.insert(ss);
        queue<string> q;
        path.insert(start);
        q.push(start);
        char list[] = {'A', 'T', 'G', 'C'};
        int lay = 0;
        while (!q.empty()) {
            int n = q.size();
            if (lay >= start.size()) break;
            lay++;
            for (int i = 0; i < n; i++) {
                string sub = q.front();
                q.pop();
                if (sub == end) return lay;
                
                for (int i = 0; i < start.size(); i++) {
                    char cmp = sub[i];
                    for (auto &ss : list) {
                        if (ss == cmp) continue;
                        sub[i] = ss;
                        if (set.count(sub) && !path.count(sub)) {
                            if (sub == end) return lay;
                            q.push(sub);
                            path.insert(sub);
                        }
                    }
                    sub[i] = cmp;
                }
            }
        }
        return -1;
    }
};



int main() {
    Solution s;
    Examples eg;
    vector<string> bank;
    bank.push_back("AACCGGTA");
    bank.push_back("AACCGCTA");
    bank.push_back("AAACGGTA");

    string start = "AACCGGTT";
    string end =   "AAACGGTA";
    cout << s.minMutation(start, end, bank) << endl;
}
