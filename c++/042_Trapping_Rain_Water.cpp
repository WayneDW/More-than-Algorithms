#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include "func.cpp"

using namespace std;

/*Given n non-negative integers representing an elevation map where the 
width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given     [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
right max    3,3,3,3,3,3,2,2,2,1,0
left max     1,1,1,2,2,2,2,3,2,2,2
*/


// stack solution
class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, pos = 0;
        stack<int> stk;
        while (pos < height.size()) {
            if (stk.empty() || height[pos] < height[stk.top()]) {
                stk.push(pos);
                pos++;
            }
            else {
                int bottom = height[stk.top()]; // record the lowest height
                stk.pop();
                if (!stk.empty()) {
                    int minHeight = min(height[stk.top()], height[pos]) - bottom;
                    res += minHeight * (pos - stk.top() - 1);
                }
            }
        }
        return res;
    }
};

int main() {
	Solution s;
    Examples eg;
    int dat[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> vec(dat, dat + sizeof(dat) / sizeof(int));
    cout << s.trap(vec) << endl;
}
