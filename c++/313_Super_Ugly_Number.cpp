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

/*Write a program to find the nth super ugly number.

Super ugly numbers are positive numbers whose all prime factors are in the given prime 
list primes of size k. For example, [1, 2, 4, 7, 8, 13, 14, 16, 19, 26, 28, 32] is the 
sequence of the first 12 super ugly numbers given primes = [2, 7, 13, 19] of size 4.

Note:
(1) 1 is a super ugly number for any given primes.
(2) The given numbers in primes are in ascending order.
(3) 0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000.
(4) The nth super ugly number is guaranteed to fit in a 32-bit signed integer.*/

// the same one with 264

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> loc(primes.size(), 0);
        int dp[n] = {1};
        for (int i = 1; i < n; i++) {
            dp[i] = INT_MAX;
            for (int j = 0; j < primes.size(); j++) {
                dp[i] = min(dp[i], dp[loc[j]] * primes[j]);
            }
            for (int j = 0; j < primes.size(); j++) {
                if (dp[i] % primes[j] == 0) loc[j]++;
            }
        }
        return dp[n-1];
    }
};

int main() {
    Solution s;
    Examples eg;
}
