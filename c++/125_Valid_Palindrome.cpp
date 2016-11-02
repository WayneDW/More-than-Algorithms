#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include "func.cpp"

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;
        while (left < right) {
            while (left < s.size() - 1 && !isalnum(s[left])) left++;
            while (right > 0 && !isalnum(s[right])) right--;
            //cout << left << " " << right << endl;
            if (left >= right) return true;
            if (tolower(s[left++]) != tolower(s[right--])) return false; // take care of left++, right++
        }
        return true;
    }
};

int main() {
	Solution s;
    Examples eg;
    cout << s.isPalindrome("......a.....") << endl;
}
