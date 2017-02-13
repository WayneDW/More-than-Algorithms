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

/*You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find 
all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, 
output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        vector<int> res;
        if (n == 0) return res;
        stk.push(nums.back());
        unordered_map<int, int> mp;
        mp[nums.back()] = -1;
        for (int i = n - 2; i >= 0; i--) {
            int val = nums[i];
            while (!stk.empty() and val > stk.top()) stk.pop();
            if (stk.empty()) mp[val] = -1;
            else mp[val] = stk.top();
            stk.push(val);
        }
        for (auto v: findNums) res.push_back(mp[v]);
        return res;
    }
};

int main() {
    Solution s;
    Examples eg;
    vector<int> findNums = {4, 1, 2};
    vector<int> nums = {1, 3, 4, 2};
    print(s.nextGreaterElement(findNums, nums));
}
