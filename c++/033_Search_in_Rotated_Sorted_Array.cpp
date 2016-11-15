#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	int n = nums.size();
    	int minimum = findMin(nums, 0, nums[0]);
    	vector<int> sub1(&nums[minimum], &nums[n]);
    	vector<int> sub2(&nums[0], &nums[minimum]);
    	sub1.insert(sub1.end(), sub2.begin(), sub2.end());
    	int loc = binSearch(sub1, target, 0);
    	if (loc == -1) return loc;
    	if (loc < n - minimum)
    		return minimum + loc;
    	else
    		return loc - n + minimum;   
    }

    
    int findMin(vector<int> nums, int loc, int firstV) {
    	int n = nums.size();
    	if (n == 1)
    		return loc;
    	else if (n == 2)
    		return (nums[0] > nums[1])? loc + 1 : 0;	
    	if (nums[n / 2] > firstV) {
    		vector<int> subNums(&nums[n / 2],  &nums[n]);
    		loc = findMin(subNums, loc + n / 2, firstV);
    	}
    	else {
    		vector<int> subNums(&nums[0], &nums[n / 2 + 1]);
    		loc = findMin(subNums, loc, firstV);
    	}
    	return loc;
    }

    int binSearch(vector<int> nums, int target, int loc) {
    	int n = nums.size();
    	if (n == 1)
    		return nums[0] == target? loc: -1;
    	if (nums[n / 2] > target) {
    		vector<int> sub(&nums[0], &nums[n / 2]);
    		loc = binSearch(sub, target, loc);
    	}
    	else {
    		vector<int> sub(&nums[n / 2], &nums[n]);
    		loc = binSearch(sub, target, loc + n / 2);
    	}
    	return loc;
    }
};

/*
14
[12, 13, 14, 15, 16, 17, 18, 19, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf, inf]
7
[-inf, -inf, -inf, -inf, -inf, -inf, -inf, -inf, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]
*/
int search(vector<int>& nums, int target) {
    int left = 0, num, right = nums.size();
    while (left < right) {
        int mid = (left + right) / 2;
        
        if (target < nums[0]) {
            if (nums[mid] < nums[0])
                num = nums[mid];
            else
                num = INT_MIN;
        }
        else {
            if (nums[mid] < nums[0])
                num = INT_MAX;
            else
                num = nums[mid];
        }
        double num = (nums[mid] < nums[0]) == (target < nums[0])
                   ? nums[mid]
                   : target < nums[0] ? -INFINITY : INFINITY;
                   
        if (num < target)
            left = mid + 1;
        else if (num > target)
            right = mid;
        else
            return mid;
    }
    return -1;
}

int main() {
	Solution s;
	int dat[] = {4,5,6,1,2,3};
	vector<int> dd(dat, dat + sizeof(dat) / sizeof(int));
	cout << s.search(dd, 4) << endl;



}
