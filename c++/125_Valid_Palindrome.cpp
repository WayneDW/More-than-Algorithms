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
        if (s.empty()) return true;
        int left = 0, right = s.size() - 1;
        while (left < right) {
            if (left < s.size() - 1 && !isalnum(s[left])) left++;
            if (right > 0 && !isalnum(s[right])) right--;
            if (left >= right) return true;
            if (s[left++] != s[right--]) return false; // take care of left++, right++
        }
    }
};


int main() {
	Solution s;
    Examples eg;
    cout << s.isPalindrome("aba ") << endl;
}
