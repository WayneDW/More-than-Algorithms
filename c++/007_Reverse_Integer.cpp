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

class Solution {
public:
    int reverse(int x) {
        int out = 0;
        while (x){
            // Take care of overflow
            if (out > INT_MAX/10 || out < INT_MIN/10){
                return 0;
            }
            out = out * 10 + x % 10;
            x = x / 10;
        }
        return out;
    }
};



int main() {
    Solution s;
    cout << s.reverse(1534236469) << endl;
}



