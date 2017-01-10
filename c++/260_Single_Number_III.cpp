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

/*Given an array of numbers nums, in which exactly two elements appear only once and all the other 
elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?*/


/*This question reminds us to use XOR, however how to do next? Owesome explanation here
https://discuss.leetcode.com/topic/25382/sharing-explanation-of-the-solution

Step 1: xor all the numbers, the result is not 0, which means at least in some position, it has 1 inside
Step 2: split it into 2 parts, one has 1 in that position, another has 0 in that position
Step 3: xor again*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        int num = 0, pos = 0, newNum1 = 0, newNum2 = 0;
        for (auto c : nums) {
            num ^= c;
        }
        while (num % 2 == 0) {
            num >>= 1;
            pos++;
        }
        for (auto c: nums) {
            if ((c >> pos) % 2) newNum1 ^= c;
            else newNum2 ^= c;
        }
        res.push_back(newNum1);
        res.push_back(newNum2);
        return res;
    }
};

int main() {
    Solution s;
    Examples eg;
    vector<int> nums = {1,2,1,3,2,5};
    printVector(s.singleNumber(nums));
}
