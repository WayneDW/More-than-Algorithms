#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	int n = nums.size();
    	if (n < 3)
    		return n;
    	int total = 2, i = 2;
    	while (i < n) {
    		if (nums[i] == nums[i - 2]) {
    			n--;
    			nums.erase(nums.begin() + i);
    			continue;
    		}
    		total++;
    		i++;
    	}
    	return total;
    }
};


int main() {
	Solution s;
}