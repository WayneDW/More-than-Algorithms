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

/*Given n points in the plane that are all pairwise distinct, a "boomerang" is a tuple of points (i, j, k) such that 
the distance between i and j equals the distance between i and k (the order of the tuple matters).

Find the number of boomerangs. You may assume that n will be at most 500 and coordinates of points are all in the 
range [-10000, 10000] (inclusive).

Example:
Input:
[[0,0],[1,0],[2,0]]

Output:
2

Explanation:
The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]*/

class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        for (auto p1: points) {
            unordered_map<int, int> mp;
            for (auto p2: points) {
                if (p1 == p2) continue;
                int dx = p1.first - p2.first;
                int dy = p1.second - p2.second;
                int dist = dx * dx + dy * dy;
                mp[dist]++;
            }
            for (auto iter: mp) {
                if (iter.second > 1) {
                    res += iter.second * (iter.second - 1);
                }
            }
        }
        return res;
    }
};


int main() {
    Solution s;
    Examples eg;
}
