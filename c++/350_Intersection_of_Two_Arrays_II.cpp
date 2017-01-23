#include <iostream>
#include <vector>
#include <map>
#include <set>
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

/*Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // if (nums2.size() > nums1.size()) return intersect(nums2, nums1);
        unordered_map<int, int> mp;
        for (auto c: nums1) mp[c]++;
        vector<int> vec;
        for (auto c: nums2) {
            if (mp[c] > 0) {
                vec.push_back(c);
                mp[c]--;
            }
        }
        return vec;
    }
};



int main() {
    Solution s;
    Examples eg;
    vector<int> nums1 = {1,2}, nums2 = {1,1};
    print(s.intersect(nums1, nums2));
}
