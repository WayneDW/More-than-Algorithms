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

/*You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:

n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.
Example 2:

n = 8

The coins can form the following rows:
¤                1
¤ ¤              3
¤ ¤ ¤            6
¤ ¤              

Because the 4th row is incomplete, we return 3.*/



/*
(1 + n) * n / 2

*/


#define CALC(k) (1 + k) * k / 2;

class Solution {
public:
    int arrangeCoins(int n) {
        long left = 1, right = n;
        while (left < right - 1) {
            long mid = left + (right - left) / 2;
            long calc = CALC(mid);
            if (calc > n) right = mid - 1;
            else if (calc == n) return mid;
            else left = mid;
        }
        long calc = CALC(right);
        return calc <= n? right: left;
    }
};

class Solution {
public:
    int arrangeCoins_better(int n) { // concise version
        long low = 1, high = n;
        while (low < high) {
            long mid = low + (high - low + 1) / 2;
            if ((mid + 1) * mid / 2.0 <= n) low = mid;
            else high = mid - 1;
        }
        return high;
    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.arrangeCoins(9) << endl;
}
