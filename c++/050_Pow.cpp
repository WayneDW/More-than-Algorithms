#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <math.h>

using namespace std;


class Solution {
public:
    double myPow(double x, int n) {
    	if (n == 0)
    		return 1;
    	if (n < 0) {
    		if (n == -pow(2, 31))
    			return x * myPow(x, n + 1);
    		return 1 / myPow(x, -n);
    	}
    	if (n == 1)
    		return x;
    	double y = myPow(x, n / 2);
    	y *= y;
    	if (n % 2 == 1)
    		y *= x;
    	return y;
    }
};


int main() {
	Solution s;
	cout << s.myPow(-1, -2147483648) << endl;


}
