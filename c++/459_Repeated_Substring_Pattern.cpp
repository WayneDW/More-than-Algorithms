#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

/*Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple 
copies of the substring together. You may assume the given string consists of lowercase English letters only 
and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)*/


class Solution {
public:
    bool repeatedSubstringPattern_string_way(string str) {
        int n = str.size();
        if (n == 1) return false;
        for (int k = 1; k <= n / 2; k++) {
            if (n % k == 0) {
                bool tag = true;
                for (int i = 0; i < k; i++) {
                    int j = i;
                    while (j + k < n) {
                        if (str[j + k] == str[j]) j += k;
                        else {
                            tag = false;
                            break;
                        }
                    }
                }
                if (tag) return true;
            }
        }
        return false;
    }

    bool repeatedSubstringPattern(string str) {
        int i = 1, j = 0, n = str.size();
        vector<int> dp(n+1,0); // dp[i+1] stores the maximum number of characters that the string is repeating itself up to position i
        while( i < str.size() ){
            if( str[i] == str[j] ) dp[++i]=++j; // ++i here: consider n + 1, it records the relation from the last digit.
            else if( j == 0 ) i++;
            else j = dp[j];
        }
        return dp[n]&&dp[n]%(n-dp[n])==0; // explanation is here: https://discuss.leetcode.com/topic/67652/c-o-n-using-kmp-32ms-8-lines-of-code-with-brief-explanation/2
    }
};

int main() {
    Solution s;
    Examples eg;
    string str = "bbbbbbaabb";
    cout << s.repeatedSubstringPattern(str) << endl;
}
