#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

class Solution {
public:
    int countDigitOne_TLE(int n) {
    	int cnt = 0;
        for (int i = 1; i <= n; i++) {
        	string t = to_string(i);
        	for (auto c: t) {
        		if (c == '1')
        			cnt++;
        	}
        }
        return cnt;
    }

    // good explanation
    // https://discuss.leetcode.com/topic/18164/5-lines-solution-using-recursion-with-explanation/2
    /*For example '8192':

	1-999 -> countDigitOne(999)

	1000-1999 -> 1000 of 1s + countDigitOne(999)

	2000-2999 -> countDigitOne(999)

	.

	.

	7000-7999 -> countDigitOne(999)

	8000-8192 -> countDigitOne(192)

	Count of 1s : *countDigitOne(999)8 + 1000 + countDigitOne(192)

	Noticed that, if the target is '1192':

	Count of 1s : *countDigitOne(999)1 + (1192 - 1000 + 1) + countDigitOne(192)

	(1192 - 1000 + 1) is the 1s in thousands from 1000 to 1192.*/
    int countDigitOne(int n) {
    	if (n < 1) return 0;
    	else if (n < 10) return 1;
    	int cnt = 0, m, q;
        int len = to_string(n).size() - 1;
        int base = pow(10, len);
        int front = n / base;
        int oneBase;
        if (front == 1)
        	oneBase = n - base + 1;
        else
        	oneBase = base;
        return countDigitOne(base - 1) * front + oneBase + countDigitOne(n % base);

    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.countDigitOne(13) << endl;
}
