#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
#include<map>
#include<string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        /*
        int sign, out;
        if (x > 0)
            sign = 1;
        else
            sign = -1;
        x = abs(x);
        while (x) {
            out = 10 * out + x % 10;
            x /= 10;
        }
        return sign * out;
        */
        int  out = 0;
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
