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

/*Given a non-empty integer array of size n, find the minimum number of moves required to 
make all array elements equal, where a move is incrementing n - 1 elements by 1.

Example:

Input:
[1,2,3]

Output:
3

Explanation:
Only three moves are needed (remember each move increments two elements):

[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minv = INT_MAX, res = 0;
        for (auto n: nums) minv = min(minv, n);
        for (auto n: nums) res += n - minv;
        return res;
    }
};


int main() {
    Solution s;
    Examples eg;
}
