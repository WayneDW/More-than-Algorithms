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

/*Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.*/

class Solution_v1 {
public:
    int findComplement(int num) {
        int i = 1, tmp = num;
        while (tmp / 2) {
            tmp /= 2;
            i = i * 2 + 1;
        }
        return num ^ i;
    }
};

class Solution {
public:
    int findComplement(int num) {
        unsigned x = ~0;
        while (num & x) x <<= 1;
        return num ^ ~x;
    }
};

int main() {
    Solution s;
    Examples eg;
    cout << s.findComplement(5) << endl;
}
