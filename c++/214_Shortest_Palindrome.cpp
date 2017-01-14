#include <iostream>
#include <vector>
#include <map>
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

/* a slow way: first we know that reverse_s + s is completely palindrome
   if we can find the right part of reverse_s and the left part of s has
   some interception, we get reduce the length;
   
    rev       S
   dcba  !=  abcd
    cba  !=  abc
     ba  !=  ab
      a  ==  a*/

class Solution { 
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.size();
        int overlap; // length of overlap

        for (overlap = n; overlap >= 0; overlap--) {
            if (rev.substr(n - overlap) == s.substr(0, overlap))
                break;
        }
        return rev.substr(0, n - overlap) + s;
    }
};

/* the best way is to use KMP algorithm, as long as we can find the longest palindrome subarray starting from left

   string                  c a t a c b | b c a t a c  (without |, we may have acaaca..we can't split it well)
   we can build a table    0 0 0 0 1 0 0 0 1 2 3 4 5
   this means the last 5 and the first 5 are the same.
   we can add b to the original string and end up with bcatacb*/

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string l = s + '|' + rev;
        vector<int> p(l.size(), 0);
        for (int i = 1; i < l.size(); i++) {
            int j = p[i - 1];
            while (j > 0 && l[j] != l[i]) {
                j = p[j - 1];
            }
            p[i] = j + (l[j] == l[i]);
        }
        return rev.substr(0, s.size() - p[l.size() - 1]) + s;
    }
};

int main() {
    Solution s;
    Examples eg;
    cout << s.shortestPalindrome("abcd") << endl;
    // cout << s.shortestPalindrome("aacecaaa") << endl;
}
