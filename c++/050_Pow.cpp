#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <math.h>

using namespace std;


class Solution2 {
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

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            if (n == -pow(2, 31)) return 1 / myPow(x, INT_MAX) / x;
            return 1 / myPow(x, -n);
        }
        if (n == 0) return 1;
        if (n == 1) return x;
        int i = 1;
        double out = x;
        while ((unsigned long long)(i * 2) < n) {
            out *= out;
            i *= 2;
        }
        cout << out << endl;
        return out * myPow(x, n - i);
    }
};

int main() {
    Solution s;
    // cout << s.myPow(-1, -2147483648) << endl;
    cout << (pow(2, 31) % 10) << endl;
    // cout << s.myPow(2, 2147483647) << endl;
}
