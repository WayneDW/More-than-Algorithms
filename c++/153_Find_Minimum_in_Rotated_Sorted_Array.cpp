#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

/*Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int mid, left = 0, right = nums.size() - 1;
        if (nums[left] < nums[right]) return nums[left];
        while (1) {
            mid = left + (right - left) / 2;
            if (nums[mid] == nums[left]) break;
            else if (nums[mid] > nums[left]) left = mid;
            else right = mid;
        }
        if (mid < right)
            return min(nums[mid], nums[mid+1]);
        else
            return nums[mid];
    }
};


int main() {
    Solution s;
    Examples eg;
    vector<int> nums;
    nums.push_back(4);
    nums.push_back(5);
    nums.push_back(6);
    nums.push_back(7);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    cout << s.findMin(nums) << endl;
}
