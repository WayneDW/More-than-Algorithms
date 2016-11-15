#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

/*
    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	sort(nums.begin(), nums.end());
    	int out = 0;
    	int MIN = pow(10, 8);
    	int len = nums.size();
    	for (int i = 0; i < len - 2; i++){
    		int left = i + 1;
    		int right = len - 1;
    		while (left < right) {
    			int total = nums[i] + nums[left] + nums[right];
    			int diff = abs(total - target);
    			if (total == target)
    				return target;
    			else if (total < target)
    				left += 1;
    			else
    				right -= 1;
    			if (diff < MIN) {
    				MIN = diff;
    				out = total;
    			}
    		}
    	}
        return out;
    }
};


int main() {
    Solution s;
    // a better way to add multi values
    int dats[] = {-1, 2, 1, -4};
    vector<int> nums(dats, dats + 4);
    cout << s.threeSumClosest(nums, 1) << endl;
	    
}
