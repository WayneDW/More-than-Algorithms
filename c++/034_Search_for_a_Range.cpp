#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	vector<int> res;
    	int n = nums.size();
    	int loc = binSearch(nums, target, 0, n - 1);
    	int i = loc, j = loc, left = loc, right = loc;
    	while (i >= 0 && nums[i] == target) {
    		left = i;
    		i--;
    	}
    	while (j < n && nums[j] == target) {
    		right = j;
    		j++;
    	}
    	
    	res.push_back(left);
    	res.push_back(right);
    	return res;
    }

    int binSearch(vector<int> &nums, int target, int left, int right) {
    	int loc, n = right - left + 1;
    	if (n == 1 && nums[left] == target)
    		return left;
    	else if (n == 1 && nums[left] != target)
    		return -1;
    	int mid = left + n / 2;
    	if (nums[mid] <= target)
    		loc = binSearch(nums, target, mid, right);
    	else
    		loc = binSearch(nums, target, left, mid - 1);
    	return loc;
    }
};


int main() {
	Solution s;
	
	int dat[] = {5, 7, 7, 8, 8, 10};
	vector<int> vec(dat, dat + sizeof(dat) / sizeof(int));
	int target = 8;
	cout << s.binSearch(vec, target, 0, 5) << endl;
	
	vector<int> res = s.searchRange(vec, target);
	for (int i = 0; i < res.size(); i++)
		cout << "ans = " << res[i] << endl;
	
}
