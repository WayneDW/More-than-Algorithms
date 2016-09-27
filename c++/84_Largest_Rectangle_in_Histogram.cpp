#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    	if (heights.size() == 0) return 0;
    	stack<int> stk;
    	heights.push_back(-1);
    	heights.insert(heights.begin(), -1);
    	int maxS = 0;
    	for (int i = 0; i < heights.size(); i++) {
    		while (!stk.empty() and heights[i] <= heights[stk.top()]) {
    			int minH = heights[stk.top()];
    			stk.pop();
    			if (!stk.empty()) maxS = max(maxS, (i - stk.top() - 1) * minH);
    		}
    		stk.push(i);
    	}
    	heights.pop_back();
    	heights.erase(heights.begin());
    	return maxS;
    }
};

int main() {
	Solution s;
}