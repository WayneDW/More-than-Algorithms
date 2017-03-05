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

/*Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....

Example:
(1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
(2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].

Note:
You may assume all input has valid answer.

Follow Up:
Can you do it in O(n) time and/or in-place with O(1) extra space?*/


/* This question in the follow up is a little tricky
three way partition: https://en.wikipedia.org/wiki/Dutch_national_flag_problem#Pseudocode

The general idea is put the number higher than median in the top, lower than median in the bottom (midian in a suitable place)

The next step is how to propose an idea that we don't directly visit nums idx = [0,1,2,3,4...], but rather visit an Array that [1,3,5., ... , 2,4,6]*/


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        // Find a median.
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        // Index-rewiring.
        #define A(i) nums[(1+2*(i)) % (n|1)] // n | 1 the lowest odd that >= n

        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid)
                swap(A(i++), A(j++)); // change value higher than mid to the left
            else if (A(j) < mid)
                swap(A(j), A(k--)); // change value lower than mid to the right
            else
                j++;
        }
    }
};


int main() {
    Solution s;
    Examples eg;
    vector<int> nums = {11,12,13,14,15,16,17,18,19};
    s.wiggleSort(nums);
}
