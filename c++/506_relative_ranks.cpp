#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

/*Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: 
"Gold Medal", "Silver Medal" and "Bronze Medal".

Example 1:
Input: [5, 4, 3, 2, 1]
Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". 
For the left two athletes, you just need to output their relative ranks according to their scores.*/

class Solution {
    static bool cmp(pair<int, int> A, pair<int, int> B) {
        return A.first < B.first;
    }
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<pair<int, int> > vec;
        vector<string> res(nums.size(), "");
        for (int i = 0; i < nums.size(); i++) vec.push_back(make_pair(nums[i], i));
        sort(vec.begin(), vec.end(), cmp);
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (i < nums.size() - 3 & nums.size() > 2) res[vec[i].second] = to_string(nums.size() - i);
            else if (i == nums.size() - 1) res[vec[i].second] = "Gold Medal";
            else if (i == nums.size() - 2) res[vec[i].second] = "Silver Medal"; 
            else res[vec[i].second] = "Bronze Medal";
        }
        return res;
    }
};
