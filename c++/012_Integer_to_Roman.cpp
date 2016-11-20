#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>


using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
		string out;
		for (int i = 0; i < 13; i++) {
			while (num >= values[i]) {
				num -= values[i];
				//out.append(numerals[i]);
				out += numerals[i];
			}
		}
		return out;
    }
};


int main() {
    Solution s;
    cout << s.intToRoman(50) << endl;
}
