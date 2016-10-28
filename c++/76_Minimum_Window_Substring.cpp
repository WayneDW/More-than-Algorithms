#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    string minWindow(string S, string T) {
        int dting[256] = {}; // use the convenience of ASCII
        for (int i = 0; i < T.size(); i++)
            dting[T[i]]++; // count the word frequency in T
        int lStart = 0, len = 0, cnt = 0, minLen = -1, bestStart = 0;
        int m = S.size(), n = T.size();
        for (int i = 0; i < S.size(); i++) {
            if (dting[S[i]] > 0)
                cnt++; // cnt == n is used to validify if we have one feasible solution
            dting[S[i]]--; // used to classify if we want to delete useless words in the boundry 
            // or surplus words even it is belong to the dict
            len++; // feasible solution length
            while (dting[S[lStart]] < 0) { // shrink the interval
                len--;
                dting[S[lStart]]++; 
                lStart++;
            }
            if (cnt == n && (len < minLen || minLen == -1)) {
                minLen = len;
                bestStart = lStart;
            }
        }
        if (cnt < n) return "";
        return S.substr(bestStart, minLen);
    }
};


int main() {
	Solution s;
    cout << s.minWindow("adobecodebanc", "abc") << endl;
}