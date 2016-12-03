#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

class Solution {
public:
    // static bool cmp(int aa, int bb) {
    //     string a = to_string(aa);
    //     string b = to_string(bb);
    //     for (int i = 0; i < min(a.size(), b.size()); i++) {
    //         if (a[i] < b[i]) return false;
    //         else if (a[i] > b[i]) return true;
    //     }
    //     if (b.size() > a.size()) {
    //         string sub = b.substr(a.size(), b.size() - a.size());
    //         return cmp(aa, stoi(sub));
    //     }
    //     else if (b.size() < a.size()) {
    //         string sub = a.substr(b.size(), a.size() - b.size());
    //         return cmp(stoi(sub), bb);
    //     }
    //     return false;
    // }

    static bool cmp(int aa, int bb) {
        string a = to_string(aa);
        string b = to_string(bb);
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        string res;
        sort(nums.begin(), nums.end(), cmp);
        bool tag = false;
        for (auto c: nums) {
            // cout << to_string(c)[0] << endl;
            string temp = to_string(c);
            if (temp[0] != '0') tag = true;
            if (tag) res += temp;
        }
        // return to_string(stoi(res)); // integer may overflow
        return res.size() > 0? res: "0";
    }
};


int main() {
    Solution s;
    Examples eg;
    vector<int> nums;
    nums.push_back(3);
    nums.push_back(30);
    nums.push_back(34);
    nums.push_back(5);
    nums.push_back(9);
    cout << s.largestNumber(nums) << endl;

    cout << stoi("00") << endl;
}
