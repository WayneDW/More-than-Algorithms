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

/*Given an array nums, there is a sliding window of size k which is moving from the very 
left of the array to the very right. You can only see the k numbers in the window. Each time 
the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].*/


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k == 1) return nums;
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++) {
            if (!dq.empty() && dq.front() == i - k) dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back(); // make sure the first as the largest
            dq.push_back(i);
            if (i >= k - 1) res.push_back(nums[dq.front()]);
        }
        return res;
    }
};

typedef pair<int, int> Pr;
class Solution { // o(Nlog N) complexity
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (k == 0) return res;
        priority_queue<Pr> heap;
        for (int i = 0; i < k; i++) heap.push(Pr(nums[i], i));
        res.push_back(heap.top().first);
        for (int i = k; i < nums.size(); i++) {
            while (!heap.empty() && heap.top().second <= i - k) heap.pop();
            heap.push(Pr(nums[i], i));
            res.push_back(heap.top().first);
        }
        return res;
    }
};

int main() {
    Solution s;
    Examples eg;
    vector<int> num = {1,3,-1,-3,5,3,6,7};
    cout << s.maxSlidingWindow(num, 3) << endl;
}
