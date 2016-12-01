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
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (auto c : nums) {
            if (s.count(c) == 0) s.insert(c);
            else return true;
        }
        return false;
    }
};


int main() {
    Solution s;
    Examples eg;
}
