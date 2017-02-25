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

/*Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

Note:
The array size can be very large. Solution that uses too much extra space will not pass the judge.

Example:

int[] nums = new int[] {1,2,3,3,3};
Solution solution = new Solution(nums);

// pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
solution.pick(3);

// pick(1) should return 0. Since in the array only nums[0] is equal to 1.
solution.pick(1);*/



// i=1 it has prob 1 to be 1; i=2 it has prob 1/2 to be 2, thus prob 1/2 to be 1
// i=3 it has prob 1/3 to be 3, thus the rest of 2 has the same probability to be 1/3

class Solution {
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int cnt = 0, res = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != target) continue;
            if (++cnt == 1) res = i;
            else if (rand() % cnt == 0) res = i;
        }
        return res;
    }
};



int main() {
    Solution s;
    Examples eg;
}
