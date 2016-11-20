#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include <sstream>
#include "000_basic.cpp"

using namespace std;


/*
1.1  1.10  

0.1  0.0.1   1

01  1    0
*/


class Solution {
public:
    int compareVersion(string version1, string version2) {
        for (auto &w : version1) w = (w == '.')? ' ' : w;
        for (auto &w : version2) w = (w == '.')? ' ' : w;
        istringstream s1(version1), s2(version2);
        while (1) {
            int n1, n2;
            if (not (s1 >> n1)) n1 = 0; // determine if s1 >> n1 has gone to the end point
            if (not (s2 >> n2)) n2 = 0; 
            if (not s1 and not s2) return 0; // not n1, n2
            if (n1 < n2) return -1;
            if (n1 > n2) return 1;
        }
    }
};

int main() {
	Solution s;
    Examples eg;
    cout << s.compareVersion("0.1", "0.0.1") << endl;
}
