#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// Math trick, understand what does permuatation mean.
// Permutation explanation:
// https://www.nayuki.io/page/next-lexicographical-permutation-algorithm

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int n = nums.size();
    	if (n < 2)
    		return;
    	// i = 0 is wrong, since we want to the first that disobey the rule from the right
    	int i = n - 2;
    	while(i >= 0 && nums[i] >= nums[i + 1])
    		i--;
    	if (i < 0) {
    		sort(nums.begin(), nums.end());
    		return;
    	}
    	int j = i + 1;
    	while (j <= n - 1 && nums[j] > nums[i])  // num[j] >= num[i] wrong
    		j++;
    	j--;
    	cout << "i = " << i << " j = " << j  << " " << nums[i] << nums[i + 1] << endl;
    	swap(nums[i], nums[j]);
    	sort(nums.begin() + i + 1, nums.end());
    }
};


int main() {
	Solution s;
	//int vec[] = {0, 1, 2, 5, 3, 3, 0};
	int vec[] = {1, 5, 1};

	//cout << sizeof(vec) / sizeof(int) << endl;
	vector<int> v(vec, vec + sizeof(vec) / sizeof(int));

	s.nextPermutation(v);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}
