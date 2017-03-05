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

/*Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1
Example 2:

Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1*/


/* math can prove that when (n + 1) % 4 == 0, n++ (except when n == 3, n--), when n is even, clearly n >>= 1
I posted the proof here https://discuss.leetcode.com/topic/59350/python-o-log-n-time-o-1-space-with-explanation-and-proof

But it seems very hard to find this rule. Thus I post a DFS solution*/

class Solution {
public:
    int integerReplacement(int n) {
        return dfs(n);
    }

    long dfs(long long n) {
        if (n == 1) return 0;
        if (n % 2 == 0) return dfs(n / 2) + 1;
        else return 1 + min(dfs(n + 1), dfs(n - 1));
    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.integerReplacement(3) << endl;
}
