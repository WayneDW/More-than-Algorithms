#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <climits>
#include <math.h>

using namespace std;

class Solution {
public:
    int abs(int x) {
        if (x >= 0)
            return x;
        else
            return -x;
    }
    int myAtoi(string str) {
        int i, j, tag = 0; 
        int n = str.size();
        unsigned long long out = 0;
        // c can do a better way of handling this by using pointer
        for (i = 0; i < n; i++) {
            if (str[i] != ' ')
                break; 
        }
        if (str[i] == '-')
            tag = -1; 
        else if (str[i] == '+')
            tag += 1;
        for (j = i + abs(tag); j < n; j++) {
            if (isdigit(str[j])) {
                // ascii transformation
                out = 10 * out + str[j] - '0';
                if ((tag == -1) & (out > (unsigned long long)INT_MAX + 1))
                    return INT_MIN;
                else if ((tag != -1) & (out > (unsigned long long)INT_MAX))
                    return INT_MAX;
            }
            else
                break;
        }
        
        if (tag == -1)
            return tag * out;
        else
            return out;
    }
};




int main() {
    Solution s;
    cout << s.myAtoi("18446744073709551617") << endl;
}


