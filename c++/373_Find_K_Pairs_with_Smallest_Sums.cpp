#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
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

/*ou are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.

Define a pair (u,v) which consists of one element from the first array and one element from the second array.

Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

Example 1:
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
Example 2:
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
Example 3:
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]*/

class Solution2 { // 32 ms
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        if (nums1.empty() || nums2.empty() || k <= 0) return res;

        auto f = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) { return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(f)> hp(f);
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                hp.push(make_pair(i, j));
            }
        }

        for (int i = 0; i < k && hp.size(); i++) {
            res.push_back(make_pair(nums1[hp.top().first], nums2[hp.top().second]));
            hp.pop();
        }
        return res;
    }
};

class Solution { // 32 ms
    struct comp {
        bool operator() (pair<int, int> a, pair<int, int> b) {
            return a.first + a.second > b.first + b.second;
        }
    };
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> res;
        if (nums1.empty() || nums2.empty() || k <= 0) return res;

        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> hp;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                hp.push(make_pair(nums1[i], nums2[j]));
            }
        }

        for (int i = 0; i < k && hp.size(); i++) {
            res.push_back(make_pair(hp.top().first, hp.top().second));
            hp.pop();
        }
        return res;
    }
};


/*  when you are at (3,2), you will push (4,2) and (3,3) later, however, when you are at (2,3) you will push(3,3) and (2,4), (3,3) can't be pushed twice
    Thus you can just push (i+1, j) given (i, j), for (i, j+1), you can do this when you are at (i-1, j). 
    The only exception is (0,j) you need push (0, j+1) and (1,j)*/


class Solution_fastest {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> result;
        if (nums1.empty() || nums2.empty() || k <= 0)
            return result;
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
        min_heap.emplace(0, 0);
        while(k-- > 0 && min_heap.size()) {
            auto idx_pair = min_heap.top(); min_heap.pop();
            result.emplace_back(nums1[idx_pair.first], nums2[idx_pair.second]);
            if (idx_pair.first + 1 < nums1.size())
                min_heap.emplace(idx_pair.first + 1, idx_pair.second);
            if (idx_pair.first == 0 && idx_pair.second + 1 < nums2.size())
                min_heap.emplace(idx_pair.first, idx_pair.second + 1);
        }
        return result;
    }
};



int main() {
    Solution s;
    Examples eg;
    vector<int> nums1 = {1,1,2}, nums2 = {1,2,3};
    print(s.kSmallestPairs(nums1, nums2, 10));
}
