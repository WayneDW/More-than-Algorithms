#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int i;
        string substring, sub = "";
        for (i = 0; i < s.size(); i++) {
            substring = ifPalin(s, i, i);
            if (substring.size() > sub.size())
                sub = substring;
            substring = ifPalin(s, i, i + 1);
            if (substring.size() > sub.size())
                sub = substring;
        }
        return sub;
    }

    string ifPalin(string s, int start, int end) {
        while (start >= 0 and end < s.size() and s[start] == s[end]) {
            start -= 1;
            end += 1;
        }
        return s.substr(start + 1, end - start - 1);
    }
};


int main() {
    Solution s;
    cout << s.longestPalindrome("abb") << endl;
    cout << s.longestPalindrome("aba") << endl;


}
