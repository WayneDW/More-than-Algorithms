#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;


class Solution {
public:
    int maximalRectangle(vector<vector<char> >& matrix) {
    	int m = matrix.size();
    	if (m == 0) return 0;
    	int n = matrix[0].size();
    	if (n == 0) return 0;
    	vector<int> dp(n, 0);
    	for (int i = 0; i < n; i++)
    		if (matrix[0][i] == '1')
    			dp[i] = 1;
    	int maxS = largestRectangleArea(dp); // use function from #84
    	for (int i = 1; i < m; i++) {
    		for (int j = 0; j < n; j++) {
    			if (matrix[i][j] == '1') // from top to bottom, iteration, reference from youTube
    				dp[j] += 1; 
    			else
    				dp[j] = 0;
    		}
    		maxS = max(maxS, largestRectangleArea(dp));
    	}
    	return maxS;
    }

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