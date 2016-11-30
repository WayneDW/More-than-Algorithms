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
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> out;
        int p = 1;
        for (int i = 0; i < nums.size(); i++) {
            out.push_back(p);
            p *= nums[i];
        }
        p = 1;
        for (int i = nums.size() - 1; i > -1; i--) {
            out[i] *= p;
            p *= nums[i];
        }
        return out;
    }
};



int main() {
	Solution s;
    Examples eg;
}
