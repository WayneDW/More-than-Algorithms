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
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st1, st2;
        for (auto c: nums1) st1.insert(c);
        vector<int> vec;
        for (auto c: nums2) if (st1.count(c) > 0) st2.insert(c);
        for (auto c: st2) vec.push_back(c);
        return vec;
    }
};


int main() {
    Solution s;
    Examples eg;
    vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
    print(s.intersection(nums1, nums2));
}
