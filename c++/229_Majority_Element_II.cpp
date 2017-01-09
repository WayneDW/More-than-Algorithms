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


/*Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. 
The algorithm should run in linear time and in O(1) space.

Hint:

How many majority elements could it possibly have?*/


/*Two, this is the Boyer-Moore Majority Vote algorithm.
This question is what I failed in Google's interview*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x = 0, y = 1, cnt_x = 0, cnt_y = 0;
        for (auto n: nums) {
            if (n == x) cnt_x++;
            else if (n == y) cnt_y++;
            else if (!cnt_x) { x = n; cnt_x = 1;}
            else if (!cnt_y) { y = n; cnt_y = 1;}
            else { cnt_x--; cnt_y--;}
        }
        // cout << cnt_x << " " << cnt_y << endl; cnt_x is not the real count for x and y
        cnt_x = cnt_y = 0;
        for (auto n : nums) { // we can't make sure that we will find the result when there aren't such numbers exist.
            if (n == x) cnt_x++;
            else if (n == y) cnt_y++;
        }
        vector<int> res;
        if (cnt_x > nums.size() / 3) res.push_back(x);
        if (cnt_y > nums.size() / 3) res.push_back(y);
        return res;
    }
};

int main() {
    Solution s;
    Examples eg;

    vector<int> nums = {2,1,1,3,5,1,3,1,2,2};
    printVector(s.majorityElement(nums));
}
