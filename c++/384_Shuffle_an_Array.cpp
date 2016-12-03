#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

class Solution {
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res(nums);
        for (int i = 0; i < nums.size(); i++) {
            int loc = rand() % (nums.size() - i);
            swap(res[i+loc], res[i]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */


int main() {
    // Solution s;
    Examples eg;
    vector<int> res;
    res.push_back(1);
    res.push_back(3);
    res.push_back(2);
    vector<int> aa(res);
    vector<int> bb = res;
    res[1] = 30;
    cout << aa[1] << endl;
}
