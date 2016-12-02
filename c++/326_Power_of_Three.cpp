#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        int divisor = pow(3, (int)(log(INT_MAX) / log(3)));
        return divisor % n == 0;
    }
};

int main() {
    Solution s;
    Examples eg;
    cout << s.isPowerOfThree(81) << endl;
}
