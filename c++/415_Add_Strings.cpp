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

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string res = "";
        while (i >= 0 || j >= 0 || carry) {
            int sum = 0;
            sum += (i >= 0? num1[i--] - '0': 0); // very consise idea
            sum += (j >= 0? num2[j--] - '0': 0) + carry;
            carry = sum / 10;
            res = to_string(sum % 10) + res;
        }
        return res;
    }
};


int main() {
    Solution s;
    Examples eg;
}
