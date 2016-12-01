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
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first) return a.first < b.first;
        return a.second < b.second;
    }
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() == 0) return false;
        vector<pair<int, int> > vec;
        pair<int, int> pr;
        for (int i = 0; i < nums.size(); i++) {
            pr.first = nums[i];
            pr.second = i;
            vec.push_back(pr);
        }

        sort(vec.begin(), vec.end(), cmp);
        for (int i = 1; i < vec.size(); i++) {
            if (vec[i].first == vec[i-1].first && abs(vec[i].second - vec[i-1].second) <= k)
                return true;
        }
        return false;
    }
};


int main() {
    Solution s;
    Examples eg;
    vector<int> res;
    res.push_back(1);
    res.push_back(2);
    res.push_back(1);
    cout << s.containsNearbyDuplicate(res, 0) << endl;
}
