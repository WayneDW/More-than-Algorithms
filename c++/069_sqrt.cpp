#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;

class Solution2 {
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

class Solution {
public:
    int mySqrt(int x) {
        if (x < 1) return 0;
        else if (x < 4) return 1;
        int left = 0, right = x;
        while (1) {
            int mid = left + (right - left) / 2;
            if (mid > x / mid) right = mid - 1;
            else {
                if ((mid + 1) > x / (mid + 1)) return mid;
                left = mid + 1;
            }
        }
    }
};

int main() {
	Solution s;
	cout << s.mySqrt(pow(2, 31) - 1) << endl;
}