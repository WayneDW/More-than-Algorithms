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
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;
            while (num) {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};


int main() {
	Solution s;
    Examples eg;
}
