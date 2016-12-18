#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return n;
        int i = 0;
        int j = 1;
        while (i < n - j) {
            if (nums[i] == nums[i + 1]) {
                nums.erase(nums.begin() + i);
                j++;
            }
            else
                i++;
        }
        return nums.size();
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        int idx = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i-1])
                nums[idx++] = nums[i];
        }
        return idx;
    }
};

int main() {
    Solution s;
    int dat[] = {1, 2, 2, 3, 3, 4};
    vector<int> set(dat, dat + 6);
    cout << set.size() << endl;
    cout << s.removeDuplicates(set) << endl;
    
}
