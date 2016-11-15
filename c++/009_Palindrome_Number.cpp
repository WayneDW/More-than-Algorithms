#include<iostream>
#include<vector>
#include<map>
#include<cmath>
#include<string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        int left, right, exp = 1;
        if (x < 0)
            return false;
        while (int(x / pow(10, exp)) != 0)
            exp += 1;
        while (x) {
            left = x / int(pow(10, exp - 1));
            right = x % 10;
            if (left != right)
                return false;
            x = (x % int(pow(10, exp - 1))) / 10;
            exp -= 2;
        }
        return true;
    }
};



int main() {
    Solution s;
    bool d;
    d = s.isPalindrome(121);
    cout << d << endl;

}
