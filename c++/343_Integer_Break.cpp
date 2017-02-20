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

/*Given a positive integer n, break it into the sum of at least two positive integers
 and maximize the product of those integers. Return the maximum product you can get.

For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).

Note: You may assume that n is not less than 2 and not larger than 58.

Hint:

There is a simple O(n) solution to this problem.
You may check the breaking results of n ranging from 7 to 10 to discover the regularities.


7 = 2 + 2 + 3 (12)
8 = 2 + 2 + 2 + 2 (16)= 3 + 5 (3*dp[5]=18)
9 = 2 + 2 + 2 + 3 (24) = 3 * 3 * 3 (27)
10 = 2 * 2 * 2 * 2 * 2 = 5 + 5 (dp[5]^2) = 3 * 3 * 2 * 2
*/

/*3 i + 2 j = n 
  i = n / 3;

*/

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        int i = n / 3;
        if (n - 3 * i == 1) i--;
        int j = (n - 3 * i) / 2;
        return pow(3, i) * pow(2, j);
    }
};

int main() {
    Solution s;
    Examples eg;
    cout << s.integerBreak(10) << endl;
}
