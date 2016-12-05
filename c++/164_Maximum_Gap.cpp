#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

class Solution2 {
public:
    int maximumGap(vector<int>& nums) { // o(nlogn time)
        if (nums.size() <= 1) return 0;
        sort(nums.begin(), nums.end());
        int gap = 0;
        int last = nums[0];
        for (auto c: nums) {
            gap = max(c - last, gap);
            last = c;
        }
        return gap;
    }
};



/*
    Bucket sort

    Given the MIN and MAX of the array, the gap between MIN and MAX is MAX-MIN, there are n-1 intervals, so the largest
    interval length, denoted as maxGap, must be larger than ceiling[(MAX-MIN)/(n-1)]

    We construct several buckets with length maxGap, each one is close to another. e.g. [5,1,3,2,4,10]

    Bucket 
       0   1    2    3
    |____|____|____|___|
    1   3|4  6|7  9|10

    we put the numbers into its corresponding bucket

    Min 1 2   4         10
    Max     3   5       10
        |____|____|____|___|
        1   3|4  6|7  9|10


    to count the maximum different, we can ignore the difference of numbers in the same busket, because they are definitely
    smaller than maxGap

    ***Remark, there are at most n groups, for example, 1, 3, 10, we can get 1-3, 4-6, 7-9 with length 3, and 10
*/


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        if (n == 2) return abs(nums[0] - nums[1]);
        vector<int> bucketMin(n, INT_MAX), bucketMax(n, INT_MIN), bucket_cnt(n, 0);
        int maxV = INT_MIN, minV = INT_MAX;
        for (auto c: nums) {
            maxV = max(c, maxV);
            minV = min(c, minV);
        }
        if (maxV - minV == 0) return 0;
        int maxGap = (maxV - minV) / (n - 1);
        maxGap = maxGap * (n - 1) == (maxV - minV)? maxGap: (maxGap + 1);
        for (auto c: nums) {
            int bucket_id = (c - minV) / maxGap;
            bucket_cnt[bucket_id]++;
            bucketMax[bucket_id] = max(bucketMax[bucket_id], c);
            bucketMin[bucket_id] = min(bucketMin[bucket_id], c);
        }
        int maxDistance = INT_MIN;
        int lastMax = bucketMin[0];
        for (int i = 0; i < n; i++) {
            if (bucket_cnt[i] == 0) continue;
            maxDistance = max(maxDistance, bucketMin[i] - lastMax);
            lastMax = bucketMax[i];
        }
        return maxDistance;
    }
};

int main() {
    Solution s;
    Examples eg;
    // vector<int> res = {100, 3, 2, 1};
    vector<int> res = {1,1,1,1,1,5,5,5,5,5};
    cout << s.maximumGap(res) << endl;
}
