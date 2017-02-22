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

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;
        if (n == 1) return 10;
        vector<int> dp(10, 0);
        dp[1] = 10;
        int sum = 0;
        for (int i = 2; i <= min(n, 10); i++) {
            dp[i] = 9;
            int j = i, k = 9;
            while (j-- > 1) {
                dp[i] *= k--;
            }
            dp[i] += dp[i-1];
        }
        return n > 10? dp[10]: dp[n];
    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.countNumbersWithUniqueDigits(3) << endl;
}
