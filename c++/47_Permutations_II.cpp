#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
    	int n = nums.size();
    	sort(nums.begin(), nums.end());
		vector<vector<int> > res;
    	if (n <= 1) {
    		res.push_back(nums);
    		return res;
    	}
    	int last = nums[0] - 1; // make sure they are not the same
    	for (int i = 0; i < n; i++) {
    		if (last == nums[i]) // recursion only when new element appears
    			continue;
    		vector<int> tmp = nums;
    		tmp.erase(tmp.begin() + i);
    		vector<vector<int> > res_part = permuteUnique(tmp);
    		for (int j = 0; j < res_part.size(); j++) {
    			res_part[j].push_back(nums[i]);
    			res.push_back(res_part[j]);
    		}
    		last = nums[i];
    	}
    	return res;
    }
};
