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

/*Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

take care of [4, 4], target = 8
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        vector<int> vec;
        for (int i = 0; i < nums.size(); i++) {
            int left = target - nums[i];
            if (mp.find(left) != mp.end()) {
                vec.push_back(i);
                vec.push_back(mp[left]);
                return vec;
            }
            mp[nums[i]] = i;
        }
        return vec;
    }
};


int main() {
    Solution s;
    Examples eg;
}
