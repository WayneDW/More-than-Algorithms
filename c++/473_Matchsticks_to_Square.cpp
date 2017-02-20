#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <numeric>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

/*Remember the story of Little Match Girl? By now, you know exactly what matchsticks the little match girl has, 
please find out a way you can make one square by using up all those matchsticks. You should not break any stick, 
but you can link them up, and each matchstick must be used exactly one time.

Your input will be several matchsticks the girl has, represented with their stick length. Your output will either 
be true or false, to represent whether you could make one square using all the matchsticks the little match girl has.

Example 1:
Input: [1,1,2,2,2]
Output: true

Explanation: You can form a square with length 2, one side of the square came two sticks with length 1.
Example 2:
Input: [3,3,3,3,4]
Output: false

Explanation: You cannot find a way to form a square with all the matchsticks.
Note:
The length sum of the given matchsticks is in the range of 0 to 10^9.
The length of the given matchstick array will not exceed 15.*/

class Solution_TLE {
public:
    bool makesquare(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0) return false;
        len = sum / 4;
        n = nums.size();
        bool tag = false;
        sort(nums.begin(), nums.end(), [](const int &l, const int &r){return l > r;});
        print(nums);
        for (int i = 0; i < n; i++) path.push_back(false);
        dfs(nums, 0, 0, tag);
        return tag;
    }

    void dfs(vector<int> &nums, int cum, int cnt, bool &tag) {            
        if (cnt == 4) {
            tag = true;
            return;
        }
        for (int i = 0; i < n; i++) {
            if (tag) break;
            if (!path[i]) {                
                if ((cum + nums[i]) % len == 0) cnt++;
                else if ((cum + nums[i]) / len > cnt) continue;
                path[i] = true;
                dfs(nums, cum + nums[i], cnt, tag);
                if ((cum + nums[i]) % len == 0) cnt--;
                path[i] = false;
            }
        }
    }
private:
    vector<bool> path;
    int n, len;
};

class Solution {
    static bool cmp(int a, int b) {
        return a > b;
    }
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0) return false;
        sort(nums.begin(), nums.end(), cmp); // greatly improve the speed
        vector<int> edges(4, 0);
        return dfs(nums, edges, 0, sum / 4);
    }

    bool dfs(vector<int>& nums, vector<int> &edges, int idx, int target) {
        if (idx == nums.size()) {
            if (edges[0] == target && edges[1] == target && edges[2] == target) return true;
            else return false;
        }

        for (int i = 0; i < 4; i++) {
            if (edges[i] + nums[idx] > target) continue; // can't return false
            edges[i] += nums[idx];

            if (dfs(nums, edges, idx + 1, target)) return true;
            edges[i] -= nums[idx];
        }
        return false;
    }
};

int main() {
    Solution s;
    Examples eg;
    vector<int> nums = {16, 2, 2, 2, 2};
    cout << s.makesquare(nums) << endl;
}
