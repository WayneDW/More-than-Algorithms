#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <climits>

using namespace std;

// class Solution2 {
// public:
//     bool isPalindrome(int x) {
//         int left, right, exp = 1;
//         if (x < 0)
//             return false;
//         while (int(x / pow(10, exp)) != 0)
//             exp += 1;
//         while (x) {
//             left = x / int(pow(10, exp - 1));
//             right = x % 10;
//             if (left != right)
//                 return false;
//             x = (x % int(pow(10, exp - 1))) / 10;
//             exp -= 2;
//         }
//         return true;
//     }
// };




// class Solution_math { // use math trick to get the first and last digit and compare
// public:
//     bool isPalindrome(int x) {
//         if (x < 0) return false;
//         int len = log(x) / log(10);
//         int exp = pow(10, len);
//         return check(abs(x), exp);
//     }
//     bool check(int x, int pow) {
//         if (pow == 1 || pow == 0) return true;
//         int last = x % 10;  // first digit 
//         int first = x / pow; // last digit
//         if (last != first) return false;
//         pow /= 10;
//         int mid = (x / 10) % pow; // choose middle part
//         if (pow == 10) return true;
//         return check(mid, pow/10);
//     }
// };

// class Solution_to_string { // this method is not only slow, but also takes extra space
// public:
//     bool isPalindrome(int x) {
//         if (x < 0) return false;
//         string s = to_string(x);
//         int l = 0, r = s.size() - 1;
//         while (l < r) {
//             if (s[l++] != s[r--]) return false;
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x > 0 && (x%10==0))) return false;
        int sum = 0;
        while (sum < x) { // only iterate half of it
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        return (sum == x) || (x == sum / 10);
    }
};

int main() {
    Solution s;
    bool d;
    d = s.isPalindrome(1221);
    // cout << sizeof(2147447412) << endl;
    // cout << sizeof(-2147447412) << endl;
    // cout << sizeof(1.1) << endl;
    // cout << sizeof(to_string(2147447412)) << endl;
    cout << d << endl;

}
