#include <iostream>
#include <vector>
#include <map>
#include <cstdlib>
#include <string>
#include <climits>

using namespace std;

/*
* Take care of overflow
* use bit shift operator, since we are not allowed to use that
* Y / x = a <=> Y = a * x <=> Y = a * (2^i + 2^j + ...)
*/


class Solution {
public:
    int divide(int dividend, int divisor) {
        unsigned int divd = dividend, divs = divisor;
        if (divisor < 0)
        	divs = -divs;
        if (dividend < 0)
        	divd = -divd;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int sign = 1;
    	if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
    		sign = -1;
         
        int res = 0;
        while(divd >= divs)
        {
            long long a = divs; // in case of overflow
            int i;
            for(i = 0; a <= divd; i++)
                a <<= 1;
            res += (1 << (i-1));
            divd -= (divs << (i-1));
        }
         
        return sign * res;
    }
};


int main() {
	Solution s;
	cout << s.divide(16, 3) << endl;
	cout << s.divide(1, 2) << endl;
}
