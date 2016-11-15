#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
    	int n = nums.size();
    	vector<vector <int> > out;
    	sort(nums.begin(), nums.end());
    	
    	for (int i = 0; i < n - 2; i++) {
    		int left = i + 1;
    		int right = n - 1;
    		if (i == 0 or nums[i] != nums[i - 1]) { // to avoid repeat
	    		while (left < right) {
	    			if (nums[i] + nums[left] + nums[right] == 0) {
	    				int tmps[] = {nums[i], nums[left], nums[right]};
	    				vector<int> tmp(tmps, tmps + sizeof(tmps) / sizeof(int));
	    				out.push_back(tmp);
                        left++;
                        right--;
                        while(nums[left]==nums[left-1]) left++;
                        while(nums[right]==nums[right+1]) right--;
	    			}
	    			else if (nums[i] + nums[left] + nums[right] < 0) {
                        left++;
	    			}
	    			else {
                        right--;
	    			}
	    		}		
    		}
    	}
    	return out;
    }
};

int main() {
    Solution s;
    int arr[] = {-1,0,1,2,-1,-4};
    vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));
    
    vector<vector<int> > out;
    out = s.threeSum(nums);
    for (int i = 0; i < out[0].size(); i++)
    	cout << out[0][i] << endl;
}
