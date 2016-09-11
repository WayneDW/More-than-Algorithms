#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
    	int n = nums.size();
    	int left = 0, right = n - 1, i = 0;
    	while (i <= right) {
    		if (nums[i] == 0)
    			swap(nums[i++], nums[left++]);
    		else if (nums[i] == 2)
    			swap(nums[i], nums[right--]);
    		else
    			i++;
    	}
    }
};


int main() {
	Solution s;
	//int dat[] = {0, 0, 1, 1, 0, 0, 2, 2, 0, 0, 1, 1, 2, 0};
	int dat[] = {2};
	vector<int> vec(dat, dat + sizeof(dat) / sizeof(int));
	s.sortColors(vec);
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";

}