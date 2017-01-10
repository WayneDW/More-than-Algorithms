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

/*Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 
For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.*/


class Solution_TLE {
public:
    int nthUglyNumber(int n) {
        unordered_set<int> history;
        int cnt = 0;
        for (int i = 1; i < INT_MAX; i++) {
            if (check_uglyNum(i, history, i)) {
                cnt++;
                if (cnt == n) {
                    return i;
                    break;
                }
            }
        }

        return 0;
    }

    bool check_uglyNum(int n, unordered_set<int> &history, int original) {
        if (n == 1 || history.count(n) > 0) {
            history.insert(original);
            return true;
        }
        if (n % 5 == 0) return check_uglyNum(n / 5, history, n);
        if (n % 3 == 0) return check_uglyNum(n / 3, history, n);
        if (n % 2 == 0) return check_uglyNum(n / 2, history, n);
        return false;
    }
};


// every ugly number except 1 can be derived from the previous one

class Solution {
public:
    int nthUglyNumber(int n) {
        int k0 = 0, k1 = 0, k2 = 0;
        int dp[n] = {1};
        for (int i = 1; i < n; i++) {
            dp[i] = min(dp[k0] * 2, min(dp[k1] * 3, dp[k2] * 5));
            if (dp[i] % 2 == 0) k0++;
            if (dp[i] % 3 == 0) k1++; // take care, not else if, e.g. 6
            if (dp[i] % 5 == 0) k2++;
        }
        return dp[n - 1];
    }
};



int main() {
    Solution s;
    Examples eg;
    cout << s.nthUglyNumber(1000) << endl;
}
