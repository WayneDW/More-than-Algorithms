#include <iostream>
#include <vector>
#include <map>
#include <set>
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

/*Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, 
we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 105.

Example:

A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
*/


/* set = [A, B, C, D]

F(0) = 0*A + 1*B + 2*C + 3*D
F(1) = 0*B + 1*C + 2*D + 3*A   F(1) - F(0) = 3A - B - C - D = 4A - SUM
F(2) = 0*C + 1*D + 2*A + 3*B   F(2) - F(1) = 3B - A - B - C = 4B - SUM*/

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.size() == 0) return 0;
        int F = 0, sum = 0, n = A.size();
        for (int i = 0; i < n; i++) {
            sum += A[i];
            F += (i * A[i]);
        }
        int res = F;
        for (int i = 1; i < n; i++) {
            F += n * A[i - 1] - sum;
            res = max(res, F);
        }
        return res;
    }
};



int main() {
    Solution s;
    Examples eg;
}
