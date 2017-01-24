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

/*Suppose you have a random list of people standing in a queue. Each person is described by a pair 
of integers (h, k), where h is the height of the person and k is the number of people in front of 
this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]*/

class Solution {
    static bool comp(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    }
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), comp);
        vector<pair<int, int>> res;
        for (auto p: people) {
            res.insert(res.begin() + p.second, p); // smart
        } 
        return res;
    }
};

int main() {
    Solution s;
    Examples eg;
    vector<pair<int,int>> people = {pair<int, int>(7,0), pair<int, int>(4,4), pair<int, int>(7,1), pair<int, int>(5,0), \
         pair<int, int>(6,1), pair<int, int>(5,2)};
    print(s.reconstructQueue(people));
}
