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

/*Additive number is a string whose digits can form additive sequence.

A valid additive sequence should contain at least three numbers. Except for the first two numbers, 
each subsequent number in the sequence must be the sum of the preceding two.

For example:
"112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.

1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
"199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
1 + 99 = 100, 99 + 100 = 199
Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.

Follow up:
How would you handle overflow for very large input integers?*/

class Solution_my_bug_version { // this framework is in genral bad
public:
    bool isAdditiveNumber(string num, int lenLeft = 0, int lenRight = 0) {
        if (num.size() == lenLeft + lenRight) return true;
        if (num.size() < 3) return false;

        string left, right, sum;

        for (int i = 1; i <= num.size() - 2; i++) { 
            if (i != 1 && num[i - 1] == '0') continue; // make sure the last digit of the number can't be 0
            if (lenLeft != 0 && lenLeft != i) continue; // when in the inner loop, skip the one that go beyond the recursion
            left = num.substr(0, i);

            for (int j = 1; j <= num.size() - i - 1; j++) { 
                if (j != 1 && num[i + j - 1] == '0') continue;
                right = num.substr(i, j);
                for (int k = 1; k <= num.size() - i - j; k++) {
                    sum = num.substr(i + j, k);
                    if (compare(left, right, sum)) {
                        cout << left << " " << right << " " << sum << endl;
                        string subString = num.substr(i, num.size() - i);
                        if (isAdditiveNumber(subString, j, k)) return true;
                    }
                }
            }
        } 
        return false;
    }

    bool compare(string left, string right, string sum) {
        if (left.size() < right.size()) return compare(right, left, sum);
        reverse(left.begin(), left.end());
        reverse(right.begin(), right.end());
        reverse(sum.begin(), sum.end());
        int i, carry = 0;
        for (i = 0; i < right.size(); i++) {
            int l = left[i] - '0', r = right[i] - '0';
            if ((l + r + carry) % 10 != sum[i] - '0') return false;
            carry = (l + r + carry) / 10;
        }
        for (i = right.size(); i < left.size(); i++) {
            int l = left[i] - '0';
            if ((l + carry) % 10 != sum[i] - '0') return false;
            carry = (l + carry) / 10;
        }
        if ((carry && sum[i] - '0' == 0) || sum.size() >= i) return false;
        return true;
    }
};


// https://discuss.leetcode.com/topic/29872/0ms-concise-c-solution-perfectly-handles-the-follow-up-and-leading-0s
class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i <= num.size() / 2; i++){ // divide by 2 saves lots of time
            for (int j = 1; j <= (num.size() - i) / 2; j++){
                if (check(num.substr(0, i), num.substr(i, j), num.substr(i + j))) return true;
            }
        }
        return false;
    }

    bool check(string num1, string num2, string num) {
        if (num1.size() > 1 && num1[0] == '0' || num2.size() > 1 && num2[0] == '0') return false;
        string sum = add(num1, num2);
        if (sum == num) return true;
        if (num.size() <= sum.size() || num.substr(0 ,sum.size()) != sum) return false;
        else return check(num2, sum, num.substr(sum.size()));
    }

    string add(string a, string b) {
        string res;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0) {
            int sum = carry + (i >= 0? (a[i--] - '0'): 0) + (j >= 0? (b[j--] - '0'): 0);
            res += sum % 10 + '0';
            carry = sum / 10;
        }
        if (carry) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};




int main() {
    Solution s;
    Examples eg;

    cout << s.isAdditiveNumber("1203") << endl;

}
