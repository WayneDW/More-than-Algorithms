#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	int n = nums.size();
    	int i = 0;
    	int j = 0;
    	while (i < n - j) {
    		if (nums[i] == val) {
    			nums.erase(nums.begin() + i);
    			j++;
    		}
    		else
    			i++;
    	}
    	return nums.size();
    }
};



int main() {
    Solution s;
    int dat[] = {1, 2, 2, 3, 3, 4};
    vector<int> set(dat, dat + 6);
    cout << set.size() << endl;
    cout << s.removeElement(set, 3) << endl;
    
}
