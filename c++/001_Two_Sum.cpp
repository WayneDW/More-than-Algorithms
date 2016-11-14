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
    vector<int> twoSum(vector<int> nums, int target) {
        int i, index1, index2, tmp;
        vector<int> vec;
        map<int, vector<int>> myMap;
        for (i = 0; i < nums.size(); i++)
            myMap[nums[i]].push_back(i); // repeat values
        index1 = -1;
        index2 = -1;
        for (i = 0; i < nums.size(); i++) {
            tmp = target - nums[i];
            if (myMap.count(tmp) > 0) {
                if (tmp != nums[i]) {
                    index1 = i;
                    index2 = myMap[tmp][0];
                    break;
                }
                // need to judge if size > 1 otherwise 6 - 3 could work unexpected
                else if (myMap[tmp].size() > 1) {
                    index1 = myMap[tmp][0];
                    index2 = myMap[tmp][1];
                    break;
                }
            }
            
        }
        vec.push_back(index1);
        vec.push_back(index2);
        return vec;
    }
};


int main() {
    Solution s;
    Examples eg;
}