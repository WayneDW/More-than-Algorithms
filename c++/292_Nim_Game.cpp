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

// math logic here
// anyone who can leave the opponent 4 can win.
// e.g. n = 7, you remove 3, then only 4 left, no matter how many steps you opponent choose, you win
// to generalize, if n = 9, you take 1, then 8 left, no matter how many steps your opponent choose, you can leave 4.
// if n = 13, you take 1, 12 left, then choose 8 left, ...
class Solution {
public:
    bool canWinNim(int n) {
        if (n % 4 == 0) return false;
        return true;
    }
};

int main() {
	Solution s;
    Examples eg;
}
