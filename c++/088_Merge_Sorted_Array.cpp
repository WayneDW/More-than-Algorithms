#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// failed in microsoft interview, what a pity
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = n + m - 1;
        while (i >= 0 && j >= 0) nums1[k--] = nums1[i] > nums2[j]? nums1[i--]:nums2[j--];
        while (j >= 0) nums1[k--] = nums2[j--];

    }
};

int main() {
	Solution s;
	vector<int> nums1;
	vector<int> nums2;
	nums1.push_back(1);
	s.merge(nums1, 1, nums2, 0);
}
