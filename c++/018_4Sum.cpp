#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

/*
For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        unordered_map<int, vector<pair<int, int> > > vPair; // TIME LIMIT EXCEEDED if using map
        vector<vector<int> > out;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // generate a dict with key = value, value = {(i, j), (k, m)}
        for (int i = 0; i < n - 1; i++) {
        	for (int j = i + 1; j < n; j++) {
        		vPair[nums[i] + nums[j]].push_back(make_pair(i, j));
        	}
        }
        
        
        for (int i = 0; i < n - 3; i++) {
        	if (i > 0 && nums[i] == nums[i - 1]) // avoid taking the same value on the 1st element
        		continue;
        	for (int j = i + 1; j < n - 2; j++) {
        		if (j > i + 1 && nums[j] == nums[j - 1]) // avoid taking the same value on the 2nd element
        			continue;
        		int T = target - nums[i] - nums[j];
        		if (vPair.count(T) > 0) {
        			bool tag = 1; // only enumerate unique value from the values of vPair 
        			for (int k = 0; k < vPair[T].size(); k++) {
	        			if (vPair[T][k].first > j) {
	        				if (tag || (out.back())[2] != nums[vPair[T][k].first]) {
	        					int tmp[4] = {nums[i], nums[j], nums[vPair[T][k].first], nums[vPair[T][k].second]};
	        					vector<int> tmpVec(tmp, tmp + 4);
	        					out.push_back(tmpVec);
	        					tag = 0;
	        				}
        				}
        			}
        		}
       		}
    	}
		/*
		// we can also use this version without deletes duplicates in the above commands
    	sort(out.begin(), out.end());
    	// take care that the last semicolon has no it++
    	for (vector<vector<int> >::iterator it = out.begin(); it != out.end();) { 
    		if (*it == *(it + 1))
    			out.erase(it); // here stop it++
    		else
    			it++; // add it++ here, otherwise can't delete duplicates perfectly
    	}*/
		
    	return out;
    }
};

int main() {
    Solution s;
    int dat[] = {-5,5,4,-3,0,0,4,-2, 1, 1, 1, 1};
    int target = 4;
    vector<int> nums(dat, dat + 12);
    vector<vector<int> > out = s.fourSum(nums, target);
    
    for (vector<vector<int> >::iterator it = out.begin(); it != out.end(); ++it) {
    	cout << " " << (*it)[0] << " " << (*it)[1] << " " << (*it)[2] << " " << (*it)[3] << endl;
    }
    
}
