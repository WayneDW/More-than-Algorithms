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

/*Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

For example,

Given numerator = 1, denominator = 2, return "0.5".
Given numerator = 2, denominator = 1, return "2".
Given numerator = 2, denominator = 3, return "0.(6)".*/

/*Use hash table to record the location that repeating appears, avoid overflow*/



class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res;
        if (numerator < 0 ^ denominator < 0) res += '-'; // determine the sign
        long n_ = abs((long)numerator), d_ = abs((long)denominator); // change to positive, avoid overflow
        res += to_string(n_ / d_); // get the interger part
        long remainder = n_ % d_; 
        if (remainder == 0) return res;
        else res += '.';

        unordered_map<int, int> dt;
        while (remainder) {
            if (dt.count(remainder) > 0) {
                res.insert(dt[remainder], 1, '('); // location, number of insertion, the string to insert
                res += ')';
                return res;
            }

            dt[remainder] = res.size(); // record the starting location when the repeating digit appears
            remainder *= 10;
            res += to_string(remainder / d_);

            remainder = remainder % d_;
        }
        return res;
    }
};

int main() {
    Solution s;
    Examples eg;
    cout << s.fractionToDecimal(-1, -2147483648) << endl;
}
