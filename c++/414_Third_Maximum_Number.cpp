#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;


class Solution {
public:
    int thirdMax(vector<int>& nums) {
        priority_queue<int> pq(nums.begin(), nums.end());
        if (nums.size() < 3) return pq.top();
        stack<int> stk;
        while (!pq.empty()) {
            if (stk.empty() || stk.top() != pq.top()) stk.push(pq.top());
            pq.top();
            if (stk.size() == 3 || pq.empty());
        }
    }
};

int main() {
    Solution s;
    Examples eg;
}
