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

// if A could go to B, while A can't go to C, this means B can't go to C
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, total = 0, tank = 0;
        for (int i = 0; i < gas.size(); i++) {
            tank += gas[i] - cost[i];
            if (tank < 0) {
                start = i + 1;
                total += tank; // if total is not negative in the end, there must be a solution
                tank = 0;
            }
        }
        return total + tank < 0? -1: start; // why + tank? [1,2], [2,1], in the last, we didn't + tank
    }
};


int main() {
    Solution s;
    Examples eg;
}
