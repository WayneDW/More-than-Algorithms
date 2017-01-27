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

/*Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) { // unordered_map and heap
        vector<int> res;
        unordered_map<int, int> mp;
        for (auto c: nums) mp[c]++;
        priority_queue<pair<int, int>> pq;
        for (auto c: mp) {
            pq.push(pair<int, int>(c.second, c.first)); // heap can sort pair with its first value
            if (pq.size() > mp.size() - k) {
                res.push_back(pq.top().second);
                pq.pop();
            }
        }
        return res;
    }
    vector<int> topKFrequent_bucket(vector<int>& nums, int k) { // bucket sort
        unordered_map<int, int> mp;
        int max_Len = 0;
        for (auto c : nums) {
            mp[c]++;
            max_Len = max(max_Len, mp[c]);
        }
        vector<int> res;
        vector<vector<int>> bucket(max_Len + 1);
        for (auto it: mp) bucket[it.second].push_back(it.first);

        for (int i = max_Len; i >= 0 && res.size() < k; i--) {
            for (auto v: bucket[i]) {
                res.push_back(v);
                if (res.size() == k) break;
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    Examples eg;
    vector<int> vec = {1, 1, 1, 2, 2, 3, 5, 5, 5};
    print(s.topKFrequent(vec, 2));
}
