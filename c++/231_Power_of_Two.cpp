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

// Given an integer, write a function to determine if it is a power of two.

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1) return true;
        if (n <= 0 || n % 2 != 0) return false;
        return isPowerOfTwo(n / 2);
    }
};

class Solution {
public:
    // if n = 10000, then n & (n - 1) = 0
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        return !(n & (n - 1));
    }
};


int main() {
    Solution s;
    Examples eg;
}
