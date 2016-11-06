#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include "func.cpp"

using namespace std;


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, cnt = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == 0) {
                nums.erase(nums.begin() + i);
                n--;
                cnt++;
            }
            else i++;
        }
        while (cnt--) {
            nums.push_back(0);
        }
    }
};

int main() {
	Solution s;
    Examples eg;
    int dat[] = {0, 1, 0, 2,3,4,5};
    vector<int> vec(dat, dat + sizeof(dat) / sizeof(int));
    s.moveZeroes(vec);
    print1dVector(vec);
}
