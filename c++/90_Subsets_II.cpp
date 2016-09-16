#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int>& nums) {
        vector<vector<int> > res;
        vector<int> part;
        res.push_back(part);
        dfs(0, nums, part, res);
        return res;
    }

    void dfs(int start, vector<int> nums, vector<int> part, vector<vector<int> > &res) {
    	if (nums.size() == start)
    		return;
    	int last = 0;
    	for (int i = start; i < nums.size(); i++) {
    		if (i != start and nums[i] == last)
    			continue;
    		part.push_back(nums[i]);
    		res.push_back(part);
    		dfs(start + 1, nums, part, res);
    		part.pop_back();
    		last = nums[i];
    	}
    }
};


int main() {
	Solution s;
}