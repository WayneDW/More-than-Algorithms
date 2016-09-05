#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
    	int n = height.size(), vol = 0;
    	vector<int> leftMax(n, 0);
    	vector<int> rightMax(n, 0);
    	for (int i = n - 2; i > 0; i--)
    		rightMax[i] = max(rightMax[i + 1], height[i + 1]);

    	for (int i = 1; i < n; i++) {
    		leftMax[i] = max(leftMax[i - 1], height[i - 1]);
    		int boundary = min(leftMax[i], rightMax[i]);
    		if (boundary > height[i])
    			vol += boundary - height[i];
    	}
    	return vol;
    }
};

