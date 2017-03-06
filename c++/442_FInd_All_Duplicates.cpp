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

/*Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements that appear twice in this array.

Could you do it without extra space and in O(n) runtime?

Example:
Input:
[4,3,2,7,8,2,3,1]

Output:
[2,3]*/

/*take care of condition of 1 <= a[i] <= n

one trick is to put every a[i] into index a[i] - 1 and set to negative, and when next time we found a negative, it must have appeared once, add it to res

another idea (without destroying the array) is set the value at nums[i] - 1 to be negative, next time when we found it neg, add it to res, and change neg back to pos*/

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        if (nums.size() == 0) return res;
        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) res.push_back(abs(nums[i]));
            else nums[idx] = -nums[idx];
        }
        // for(int i = 0; i < nums.size(); i++)
        //     nums[i] = abs(nums[i]);
        for (auto &c : nums) c = abs(c);
        return res;
    }
};

int main() {
    Solution s;
    Examples eg;
}
