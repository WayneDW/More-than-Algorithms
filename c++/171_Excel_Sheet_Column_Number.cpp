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

/*  A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 */

class Solution {
public:
    int titleToNumber(string s) {
        int sum = 0;
        for (auto c: s) {
            sum = sum * 26 + (c - 'A' + 1);
        }
        return sum;
    }
};


int main() {
    Solution s;
    Examples eg;
}
