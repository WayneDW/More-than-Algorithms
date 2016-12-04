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


/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
*/


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int preMax = nums[0], preMin = nums[0], res = nums[0];
        int nowMax, nowMin;
        for (int i = 1; i < nums.size(); i++) {
            nowMax = max(nums[i], max(preMax * nums[i], preMin * nums[i]));
            nowMin = min(nums[i], min(preMax * nums[i], preMin * nums[i]));
            res = max(res, nowMax);
            preMax = nowMax;
            preMin = nowMin;
        }
        return res;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        int leftward = 1, rightward = 1, n = nums.size();
        int res = INT_MIN;
        for (int i = 0; i < n; i++) {
            leftward *= nums[i];
            rightward *= nums[n-1-i];
            res = max(res, max(leftward, rightward));
            leftward = nums[i] == 0 ? 1 : leftward;
            rightward = nums[n-1-i] == 0 ? 1 : rightward;

        }
        return res;
    }
};

int main() {
    Solution s;
    Examples eg;
    // vector<int> res = {6,3,-10,0,2};
    vector<int> res = {2,-5,-2,-4,3};
    cout << s.maxProduct(res) << endl;
}
