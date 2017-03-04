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

/*Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.

Example1:

a = 2
b = [3]

Result: 8
Example2:

a = 2
b = [1,0]

Result: 1024*/



/* https://leetcode.com/problems/super-pow/?tab=Solutions

Basic idea follows this:

since (a * b) mod k = (a mod k) * (b mod k) mod k

Thus a^123 mod k = a^120 mod k * (a^3 mod k) mod k = (a^12 mod k) ^ 10 mod k * (a^3 mod k) mod k 

In a word: f(a, k) = f(f(a, b/10), 10) * f(a, b%10) mod k */


class Solution {
    const int base = 1337;

    int largeMod(int a, int c) {
        a %= base;
        int result = 1;
        while (c-- > 0) result = (result * a) % base;
        return result;
    }

public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        int last = b.back(); b.pop_back();
        return largeMod(superPow(a, b), 10) * largeMod(a, last) % base;
    }
};


int main() {
    Solution s;
    Examples eg;
    vector<int> b = {1, 0};
    cout << s.superPow(2, b) << endl;
}
