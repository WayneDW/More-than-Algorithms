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

/*Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB */

class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while (n > 0) {
            char ch = (n - 1) % 26 + 'A';
            res = ch + res; // take care of order
            n = (n - 1) / 26; // remember to change to 0 based
        }
        return res;
    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.convertToTitle(52) << endl;
}
