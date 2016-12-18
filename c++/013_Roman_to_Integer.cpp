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
        string numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}; // 13
        int i = 0;
        int out = 0;
        int start = 0;
        while (i < 13 && start < s.size()){
            string tmp = s.substr(start, numerals[i].size());
            if (tmp == numerals[i]) {
                start += numerals[i].size();
                out += values[i];
            }
            else i++;
        }
        return out;
    }
};

int romanToInt(string s) 
{
    unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };
                                   
   int sum = T[s.back()];
   for (int i = s.length() - 2; i >= 0; --i) {
       if (T[s[i]] < T[s[i + 1]]) sum -= T[s[i]];
       else sum += T[s[i]];
   }
   return sum;
}


int main() {
    Solution s;
    cout << s.romanToInt("MXIIIIII") << endl;
}
