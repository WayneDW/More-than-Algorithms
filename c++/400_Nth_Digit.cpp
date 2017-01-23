#include <iostream>
#include <vector>
#include <map>
#include <set>
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

/*Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...

Note:
n is positive and will fit within the range of a 32-bit signed integer (n < 231).

Example 1:

Input:
3

Output:
3
Example 2:

Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.*/


class Solution { // bug existed in somewhere, give up fixing it.
public:
    int findNthDigit(int n) {
        if (n < 10) return n;
        vector<int> thres_digits;
        int last = 10, digits;
        thres_digits.push_back(9);
        for (int i = 2; i < 10; i++) {
            thres_digits.push_back(i * (9 * last) + thres_digits.back());
            last *= 10;
        }
        for (digits = 8; digits >= 0; digits--) {
            cout << thres_digits[digits] << " " << n << " " << digits << endl;
            if (thres_digits[digits] < n) break;
        }
        int kth = n - thres_digits[digits] - 1; // 250-> 63th digit starting with 100
        int target = pow(10, digits + 1) + kth / (digits + 2); // the target number is 120
        char res = to_string(target)[kth % (digits + 2)];
        return res - '0';
        // return atoi(res);
    }
};

class Solution { // others' version
public:
    int findNthDigit(int n) {
        // step 1. calculate how many digits the number has.
        long base = 9, digits = 1;
        while (n - base * digits > 0) {
            n -= base * digits;
            base *= 10;
            digits ++;
        }

        // step 2. calculate what the muber is.
        int index = n % digits;
        if (index == 0)
            index = digits;
        long num = 1;
        for (int i = 1; i < digits; i ++)
            num *= 10;
        num += (index == digits) ? n / digits - 1 : n / digits;;

        // step 3. find out which digit in the number is we want.
        for (int i = index; i < digits; i ++)
            num /= 10;
        return num % 10;
    }
};

int main() {
    Solution s;
    Examples eg;
    cout << s.findNthDigit(1000000000) << endl;
}
