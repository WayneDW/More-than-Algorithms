#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include "func.cpp"

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        for (auto i : nums)
            sum += i;
        int n = nums.size();
        return n * (n + 1) / 2 - sum;
    }
};

class Solution2 { // if nums is sorted
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > mid) right = mid;
            else left = mid + 1;
        }
        return right;
    }
};

int main() {
	Solution s;
    Examples eg;
}
