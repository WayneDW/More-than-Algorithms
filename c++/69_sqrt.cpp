#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
    	if (x < 1)
    		return 0;
    	else if(x < 4)
    		return 1;
    	int l = 0, r = x;
    	while (l < r - 1) {
    		long int mid = (l + r) / 2;
    		if (mid * mid == x)
    			return mid;
    		else if (mid * mid > x)
    			r = mid;
    		else
    			l = mid;
    	}
    	return l;
    }
};



int main() {
	Solution s;
	cout << s.mySqrt(2147395599) << endl;
}