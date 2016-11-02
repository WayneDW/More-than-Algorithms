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


class Solution3 { // bad method
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int last = 1;
        if (nums[0] != nums[1]) return nums[0];
        for (int i = 1; i < nums.size() - 1; i++) {
            if (last && nums[i] == nums[i-1])
                last = 1;
            else if (last && nums[i] != nums[i+1])
                return nums[i];
        }
        return nums[nums.size()-1];
    }
};

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> dt;
        unordered_map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); i++) {
            if (dt.find(nums[i]) == dt.end())
                dt[nums[i]] = 1;
            else
                dt.erase(nums[i]);
        }
        for (auto x: dt) // either way is fine
            return x.first;
        // for (it = dt.begin(); it != dt.end(); ++it)
        //     return it->first;
        return 0;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i < nums.size(); i++)
            res ^= nums[i];
        return res;
    }
};


int main() {
	Solution s;
    Examples eg;
    vector<int> res;
    res.push_back(3);
    res.push_back(2);
    res.push_back(2);
    cout << s.singleNumber(res);


}
