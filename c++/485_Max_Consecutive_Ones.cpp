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

/*Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxV = 0, curMax = 0;
        for (auto i: nums) {
            curMax = (i ? curMax + 1: 0);
            maxV = max(curMax, maxV);
        }
        return maxV;
    }
};

int main() {
    Solution s;
    Examples eg;
}
