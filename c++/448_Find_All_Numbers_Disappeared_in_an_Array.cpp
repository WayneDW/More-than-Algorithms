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

/*Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        vector<int> cnt(nums.size() + 1, 1);
        for (auto n: nums) cnt[n] = 0;
        vector<int> res;
        for (int i = 1; i <= nums.size(); i++) {
            if (cnt[i] == 1) res.push_back(i);
        }
        return res;
    }
};

// Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1; // take care of abs
            nums[idx] = -abs(nums[idx]);
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) res.push_back(i + 1);
            else nums[i] = -nums[i]; // without destroying the array
        }
        return res;
    }
};

int main() {
    Solution s;
    Examples eg;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    print(s.findDisappearedNumbers(nums));
}
