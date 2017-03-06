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

/*Given a non-empty integer array, find the minimum number of moves required to make all array 
elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.

You may assume the array's length is at most 10,000.

Example:

Input:
[1,2,3]

Output:
2

Explanation:
Only two moves are needed (remember each move increments or decrements one element):

[1,2,3]  =>  [2,2,3]  =>  [2,2,2]*/


class Solution_lib { // use library to find the median
public:
    int minMoves2(vector<int>& nums) {
        auto it = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), it, nums.end());
        int median = *it, res = 0;
        for (auto c: nums)
            res += abs(c - median);
        return res;
    }
};

class Solution { // write quicksort by myself
public:
    int minMoves2(vector<int>& nums) {
        int res = 0, n = nums.size();
        int median = find_k(nums, 0, n - 1, n/2 + 1);
        for (auto c: nums)
            res += abs(c - median);
        return res;
    }

private:
    int find_k(vector<int> &nums, int l, int r, int k) {
        int left = l, right = r, pivot = nums[r];
        while (1) {
            while (nums[left] < pivot && left < right) left++; // take care while
            while (nums[right] >= pivot && left < right) right--;
            if (left == right) break;
            swap(nums[left], nums[right]); 
        }
        swap(nums[left], nums[r]); // change pivot to the corresponding place

        if (k == left + 1) return pivot;
        else if (k < left + 1) return find_k(nums, l, left - 1, k);
        else return find_k(nums, left + 1, r, k);
    }
};


int main() {
    Solution s;
    Examples eg;
    vector<int> nums = {1,2,3};
    cout << s.minMoves2(nums) << endl;
}
