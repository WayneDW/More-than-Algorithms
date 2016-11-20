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
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n >= 1) {
            if (n % 2 == 1) res++;
            n /= 2;
        }
        return res;
    }
};


int main() {
	Solution s;
    Examples eg;
}
