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

/*There is a list of sorted integers from 1 to n. Starting from left to right, remove 
the first number and every other number afterward until you reach the end of the list.

Repeat the previous step again, but this time from right to left, remove the right most 
number and every other number from the remaining numbers.

We keep repeating the steps again, alternating left to right and right to left, until 
a single number remains.

Find the last number that remains starting with a list of length n.

Example:

Input:
n = 9,
1 2 3 4 5 6 7 8 9
2 4 6 8
2 6
6

Output:
6*/

/*Josephus Problem: log(N) time complexity
https://discuss.leetcode.com/topic/59293/java-easiest-solution-o-logn-with-explanation
if N is even and we start from right to left, the number doesn't change
4 6 8 10     here if we start from 4, after this loop, 4 still exists
  x    x*/


class Solution {
public:
    int lastRemaining(int n) {
        int head = 1, step = 1;
        bool left = true;
        while (n > 1) {
            if (left || n % 2 == 1) {
                head += step;
            }
            n /= 2;
            step *= 2;
            left = !left;
        }
        return head;
    }
};

/*After first elimination, all the rest numbers are even numbers.
Divide by 2, we get a continuous new sequence from 1 to n / 2.
For this sequence we start from right to left as the first elimination.
Then the original result should be two times the mirroring result of lastRemaining(n / 2).

int lastRemaining(int n) {
    return n == 1 ? 1 : 2 * (1 + n / 2 - lastRemaining(n / 2));
}*/


int main() {
    Solution s;
    Examples eg;
    cout << s.lastRemaining(9) << endl;
}
