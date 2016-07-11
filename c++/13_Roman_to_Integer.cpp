#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
    	int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int i = 0;
		int out = 0;
        int start = 0;
        while (i < 13 && start < s.size()){
            string tmp = s.substr(start, numerals[i].size());
            if (tmp == numerals[i]) {
                start += numerals[i].size();
                out += values[i];
            }
            else {
                i += 1;
            }
        }
		return out;
    }
};


int main() {
    Solution s;
    cout << s.romanToInt("MXIIIIII") << endl;


}
