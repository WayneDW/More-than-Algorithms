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

/*Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?*/

class Solution {
public:
    bool isPowerOfFour(int num) {
        int cmp = 1, bak = num;
        while (bak > 1) {
            bak >>= 2;
            cmp <<= 2;
        }
        return cmp == num;
    }
};

class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0) && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.isPowerOfFour(15) << endl;
}
