#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution_2 {
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

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() == 0) return NULL;
        string res;
        int max_len = 1, left, right, best_loc = 0;
        for (int i = 0; i < s.size();) {
            left = right = i;
            // this format fails when cbba with 2 consecutive b, thus we need to check duplicate
            // while (left > 0 && right < s.size() -1 && s[left] == s[right]) {
            //     left--;
            //     right++;
            // }
            while (right + 1 < s.size() && s[right + 1] == s[right]) right++; // skip duplicate
            i = right + 1;
            while (left - 1 >= 0 && right + 1 <= s.size() -1 && s[left-1] == s[right+1]) { left--; right++;}
            int cur_len = right - left + 1;
            if (cur_len > max_len) {
                max_len = cur_len;
                best_loc = left;
            }
        }
        return s.substr(best_loc, max_len);
    }
};