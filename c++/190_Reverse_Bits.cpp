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
#include <bitset>
#include "000_basic.cpp"

using namespace std;

/*Reverse bits of a given 32 bits unsigned integer.

For example, given input 43261596 return 964176192
binary as 00000010100101000001111010011100
          00111001011110000010100101000000

Follow up:
If this function is called many times, how would you optimize it?*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0;
        for (int i = 0; i < 31; i++) {
            m |= (n & 1); // take the 1st loc as its 32th loc, 2nd .. as 31...
            n >>= 1;
            m <<= 1;
        }
        m |= (n & 1);
        return m;
    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.reverseBits(1) << endl;
}
