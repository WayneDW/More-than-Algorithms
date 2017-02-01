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

/*Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5*/

class Solution {
public:
    int countSegments_a_little_slow(string s) {
        stringstream ss(s);
        int cnt = 0;
        string tmp;
        while (ss >> tmp) {
            cnt++;
            cout << ss.str() << endl;
        }
        return cnt;
    }

    int countSegments(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++)
            res += s[i] != ' ' && (i + 1 == s.size() || s[i+1] == ' ');
        return res;
    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.countSegments("a b c") << endl;
}
