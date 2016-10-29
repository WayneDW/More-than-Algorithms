#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumpM = 0, lastJump = 0;
        int i = 0, k = 0, tag = 0;
        while (jumpM < n - 1) {
            while (i <= lastJump) {
                jumpM = max(jumpM, i + nums[i]);
                if (jumpM < i + 1) {
                    tag = 1;
                    break;
                }
                i++;
            }
            k++;
            lastJump = jumpM;
        }
        if (tag)
            return 0;
        return k;
    }
};


int main() {
	Solution s;
}