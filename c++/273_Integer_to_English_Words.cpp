#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

/*Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Hint:

Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
Group the number by thousands (3 digits). You can write a helper function that takes a number less than 1000 and 
convert just that chunk to words.
There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 1000010? 
(middle chunk is zero and should not be printed out)*/

class Solution {
    vector<string> below_20 =  {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", \
        "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
    vector<string> below_100 = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string int_string(int n) {
        if (n >= 1000000000) return int_string(n / 1000000000) + " Billion" + int_string(n - 1000000000 * (n / 1000000000));
        else if (n >= 1000000) return int_string(n / 1000000) + " Million" + int_string(n - 1000000 * (n / 1000000));
        else if (n >= 1000) return int_string(n / 1000) + " Thousand" + int_string(n - 1000 * (n / 1000));
        else if (n >= 100) return int_string(n / 100) + " Hundred" + int_string(n - 100 * (n / 100));
        //  take care of projection for below_100
        else if (n >= 20) return " " + below_100[n / 10 - 2] + int_string(n - 10 * (n / 10));
        else if(n >= 1) return " " + below_20[n - 1];
        else return ""; // return something like for 1000
    }

public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        string res = int_string(num);
        return res.substr(1);
    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.numberToWords(1000) << endl;
}
