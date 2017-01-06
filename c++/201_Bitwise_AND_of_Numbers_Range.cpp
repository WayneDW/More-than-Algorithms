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

/*Given a range [m, n] where 0 <= m <= n <= 2147483647,
return the bitwise AND of all numbers in this range, inclusive.

For example, given the range [5, 7], you should return 4.*/


/*this question is a little hard to understand.
one explains here: https://discuss.leetcode.com/topic/20176/2-line-solution-with-detailed-explanation*/

class Solution {
public:
    /*if n > m, the rightest digit is 0, we transform this question into subproblem*/
    int rangeBitwiseAnd(int m, int n) {
        return (n > m) ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.rangeBitwiseAnd(100, 1000000000) << endl;
}
