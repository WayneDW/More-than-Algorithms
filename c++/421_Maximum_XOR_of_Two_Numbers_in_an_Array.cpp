#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
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

/*Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

Could you do this in O(n) runtime?

Example:

Input: [3, 10, 5, 25, 2, 8]

Output: 28

Explanation: The maximum result is 5 ^ 25 = 28.*/


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maximum = 0, mask = 0;
        for (int i = 31; i >= 0; i--) {
            mask |= (1 << i);
            unordered_set<int> st;
            for (auto c: nums) st.insert(c & mask);

            // Extremly important property:
            // set has unique values, if A ^ B = candidate, then candidate ^ A = B, which also means
            // candidate ^ A = B => A ^ B = candidate
            int candidate = maximum | (1 << i);
            for (auto A: st) {
                if (st.find(A ^ candidate) != st.end()) {
                    maximum = candidate;
                    break;
                }
            }
        }
        return candidate;
    }
};

int main() {
    Solution s;
    Examples eg;
    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << s.findMaximumXOR(nums) << endl;
}
