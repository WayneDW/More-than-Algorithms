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

/*You are a product manager and currently leading a team to develop a new product. 
Unfortunately, the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, 
all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first 
bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version 
is bad. Implement a function to find the first bad version. You should minimize 
the number of calls to the API.*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion_complex(int n) {
        int left = 0, right = n - 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid + 1)) right = mid;
            else left = mid + 1;
        }
        bool tag = isBadVersion(left + 1);
        return tag? left + 1: right + 1;
    }

    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};


int main() {
    Solution s;
    Examples eg;
}
