#include <iostream>
#include <vector>
#include <map>
#include <set>
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

/*Given an array of integers, find out whether there are two distinct indices 
i and j in the array such that the absolute difference between nums[i] and nums[j]
 is at most t and the absolute difference between i and j is at most k.*/


/*we keep a window of length k, we want to find if there exists i and j such that -t <= nums[j] - nums[i] <= t

x + nums[i] >= -t <==>  x >= nums[i] - t, using lower_bound, if we can found x satisfying that condition, we solved one part*/


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> window;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) window.erase(nums[i - k - 1]);
            auto it = window.lower_bound((long long)nums[i] - t);  // using upper_bound has some bugs here, see main()
            if (it != window.end() && *it - nums[i] <= t) return true;
            window.insert(nums[i]);
        }
        return false;
    }
};

// time: O(n); space: O(n), https://discuss.leetcode.com/topic/42497/o-n-solution-in-c-using-bucket-sort
class Solution {
    long long getBucketId(long long i, long long w) {
        return i < 0 ? (i + 1) / w - 1 : i / w;
    }
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        if (n < 2 || k < 1 || t < 0) return false;

        unordered_map<long long, long long> buckets; // map bucket id to element value
        long long width = (long long)t + 1;
        for (int i = 0; i < n; i++) {
            long long id = getBucketId(nums[i], width);
            if (buckets.count(id) > 0) return true; // before applying this value, that bucket already existed

            // found the value in the adjacent bucket
             if ((buckets.count(id - 1) > 0 && nums[i] - buckets[id - 1] < width) ||
                 (buckets.count(id + 1) > 0 && buckets[id + 1] - nums[i] < width)) {
                return true;
            }

            // insert current value to buckets
            buckets[id] = nums[i];
            // remove out of range element
            if (i >= k) buckets.erase(getBucketId(nums[i - k], width)); // make sure the difference of locations <= k
        }
        return false;
    }
};
// this question is better solved by bucket sort

int main() {
    Solution s;
    Examples eg;
    vector<int> nums = {-1,-1};
    cout << s.containsNearbyAlmostDuplicate(nums, 1, 0) << endl;


    set<int> ss;
    ss.insert(-1);
    auto it1 = ss.lower_bound(-1);
    auto it2 = ss.upper_bound(-1);
    cout << *it1 << " " << *it2 << endl; // bug here, return -1 1
}
