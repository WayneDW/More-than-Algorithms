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

/*Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Returns: True
Example 2:

Input: 14
Returns: False*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1, r = num;
        long long mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            cout << l << " " << mid << " " << r << endl;
            if (mid * mid == num) return true;
            else if (mid * mid > num) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};

int main() {
    Solution s;
    Examples eg;
    cout << s.isPerfectSquare(104976) << endl;
}
