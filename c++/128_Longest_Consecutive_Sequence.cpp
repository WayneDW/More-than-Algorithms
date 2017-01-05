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

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int cnt = 1;
        for (int i : nums) {
            if (st.count(i) == 0) continue;
            st.erase(i);
            int prev = i - 1, next = i + 1;
            while (st.count(prev) > 0) st.erase(prev--); // without erase still works, yet too slow
            while (st.count(next) > 0) st.erase(next++);
            cnt = max(cnt, next - prev - 1);
        }
        return cnt;
    }
};


int main() {
    Solution s;
    Examples eg;
}
