#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));            
        } while (slow != fast);
        if (slow == 1) return 1;
        else return 0;
    }

    int squareSum(int num) {
        int sum = 0;
        while (num) {
            sum += pow(num % 10, 2);
            num /= 10;
        }
        return sum;
    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.isHappy(19) << endl;
}
