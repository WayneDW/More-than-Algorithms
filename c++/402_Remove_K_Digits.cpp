#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
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

/*Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.*/


/*idea: delete the first number that is larger than its right position*/

class Solution { // pass cases 25/33, actually failed
public:
    string removeKdigits2(string num, int k) {
        string res = tool(num, k);
        return res == ""? "0": res;
    }

    string tool(string num, int k) {
        if (k == 0) return num;
        int cnt_0 = 0;
        for (auto c: num) if (c != '0') cnt_0 += 1;
        if (k >= cnt_0) return "";

        string res = "";
        int i = 0;
        for (; i < num.size() - 1; i++) {
            if (num[1] == '0') { // handle case like 107 -> 17 (however 1107 should return 107)
                res += tool(num.substr(i + 2), k - 1);
            }
            else if (num[i] > num[i + 1]) {
                if (i >= 1) res += num.substr(0, i);
                if (i + 1 < num.size()) res += tool(num.substr(i + 1), k - 1);
            }
            break;
        }
        if (i == num.size() - 1) res += tool(num.substr(0,i), k - 1);
        return res;
    }
    string removeKdigits(string num, int k) {
        string res = "";
        int keep = num.size() - k;
        for (auto c: num) {
            while (res.size() && res.back() > c && k > 0) { // while 
                res.pop_back();
                k--; // only delete here, since only here did we complete one delete
            }
            res += c;
        }
        res.erase(keep); // should not use num.size() - k instead of keep
        // trim leading 0
        int i0 = 0;
        while (res[i0] == '0') i0++;
        res = res.substr(i0);

        return res == "" ? "0" : res;
    }
};



int main() {
    Solution s;
    Examples eg;
    cout << s.removeKdigits("1107", 1) << endl;
}
