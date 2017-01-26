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

/*A sequence of number is called arithmetic if it consists of at least three elements and if 
the difference between any two consecutive elements is the same.

For example, these are arithmetic sequence:

1, 3, 5, 7, 9
7, 7, 7, 7
3, -1, -5, -9
The following sequence is not arithmetic.

1, 1, 2, 5, 7

A zero-indexed array A consisting of N numbers is given. A slice of that array is any pair of 
integers (P, Q) such that 0 <= P < Q < N.

A slice (P, Q) of array A is called arithmetic if the sequence:
A[P], A[p + 1], ..., A[Q - 1], A[Q] is arithmetic. In particular, this means that P + 1 < Q.

The function should return the number of arithmetic slices in the array A.


Example:

A = [1, 2, 3, 4]

return: 3, for 3 arithmetic slices in A: [1, 2, 3], [2, 3, 4] and [1, 2, 3, 4] itself.*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) { // slow version, double loop
        int n = A.size();
        if (n < 3) return 0;
        int dp[n] = {0}; // dp[i]: number of results starting at i
        int sum = 0;
        
        for (int i = 0; i < A.size() - 2; i++) {
            if (A[i + 1] - A[i] == A[i + 2] - A[i + 1]) dp[i] = 1;
            while (dp[i] && i + dp[i] + 2 < n && A[i + dp[i] + 2] - A[i + dp[i] + 1] == A[i + 1] - A[i]) dp[i]++;
            sum += dp[i];
        }
        return sum;
    }

    int numberOfArithmeticSlices(vector<int>& A) { // one loop version
        int n = A.size();
        if (n < 3) return 0;
        int dp[n] = {0}; // dp[i]: number of results ending at i
        if (A[2] + A[0] == 2 * A[1]) dp[2] = 1;
        int sum = dp[2]; // cause i starts at 3
        for (int i = 3; i < A.size(); i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) dp[i] = dp[i - 1] + 1;
            sum += dp[i];
        }
        return sum;
    }
};

int main() {
    Solution s;
    Examples eg;
}
