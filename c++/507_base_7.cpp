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
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool sign = true;
        if (num < 0) sign = false;
        string res = "";
        num = abs(num);
        while (num) {
            res = to_string(num % 7) + res;
            num /= 7;
        }
        return sign? res: '-' + res;
    }
};