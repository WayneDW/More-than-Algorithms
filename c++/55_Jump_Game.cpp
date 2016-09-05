#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
    	int n = nums.size(), idx = 0;
    	if (n <= 1)
    		return true;
    	for (int i = 0; i < n - 1; i++) {
    		idx = max(idx, i + nums[i]);
    		if (idx < i + 1)
    			break;
    		if (idx >= n - 1)
    			return true;
    	}
    	return false;
    }
};
