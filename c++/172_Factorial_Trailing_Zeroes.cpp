#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include "func.cpp"

using namespace std;

/*Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.*/

class Solution {
public:
    int trailingZeroes(int n) {
        int pow = log(n) / log(5);
        int sum = 0, div = 5;
        while (pow-- > 0) {
            sum += n / div;
            div*= 5;
        }
        return sum;
    }
};


int main() {
	Solution s;
    Examples eg;
    cout << s.trailingZeroes(50) << endl;
}
