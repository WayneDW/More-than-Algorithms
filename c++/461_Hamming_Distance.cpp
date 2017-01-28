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

/*The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.

Note:
0 ≤ x, y < 231.

Example:

Input: x = 1, y = 4

Output: 2

Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑

The above arrows point to positions where the corresponding bits are different.*/

class Solution {
public:
    int hammingDistance(int x, int y) {
        int res = 0, i = 0;
        while (i++ < 32) {
            res += (x & 1) ^ (y & 1);
            x >>= 1;
            y >>= 1;
            cout << x << " " << y << endl;
        }
        return res;
    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.hammingDistance(1, 4) << endl;
}
