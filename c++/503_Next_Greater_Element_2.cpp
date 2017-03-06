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

/*Given a circular array (the next element of the last element is the first element of the array), 
print the Next Greater Number for every element. The Next Greater Number of a number x is the first 
greater number to its traversing-order next in the array, which means you could search circularly 
to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size());
        int n = nums.size();
        if (n == 0) return res;
        int maximum = INT_MIN, pivot = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maximum) {
                maximum = nums[i];
                pivot = i;
            }
        };
        
        stack<int> stk;
        stk.push(maximum);
        res[pivot] = -1;
        for (int i = pivot - 1; i >= 0; i--) {
            while (nums[i] >= stk.top() && stk.top() != maximum) stk.pop(); // don't need to worry about empty stack
            if (nums[i] == maximum) res[i] = -1;
            else res[i] = stk.top();
            stk.push(nums[i]);
        }

        for (int i = n - 1; i >= pivot; i--) {
            while (nums[i] >= stk.top() && stk.top() != maximum) stk.pop(); // don't need to worry about empty stack
            if (nums[i] == maximum) res[i] = -1;
            else res[i] = stk.top();
            stk.push(nums[i]);
        }
        return res;
    }
};

int main() {
    Solution s;
    Examples eg;
    vector<int> nums = {1, 2, 5, 3, 9, 4, 9, 1};
    print(s.nextGreaterElements(nums));
}