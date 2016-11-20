#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int loc = binSearch(nums, target, 0, nums.size() - 1);
        if (nums[loc] == target)
        	return loc;
        else if (nums[loc] < target)
        	return loc + 1;
       	return 0;
    }

	int binSearch(vector<int> &nums, int target, int left, int right) {
    	int loc, n = right - left + 1;
    	if (n == 1)
    		return left;
    	int mid = left + n / 2;
    	if (nums[mid] <= target)
    		loc = binSearch(nums, target, mid, right);
    	else
    		loc = binSearch(nums, target, left, mid - 1);
    	return loc;
    }
};

int main() {



}
