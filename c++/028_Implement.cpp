#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;


class Solution{
public:
    int strStr(string haystack, string needle) {
    	int m = needle.size();
    	int n = haystack.size();
    	if (m == 0)
    		return 0;
    	if (n == 0)
    		return -1;
    	
    	for (int i = 0; i < n - m + 1; i++) {
    		int j = 0;
    		while (j < m) {
    			char p = haystack[i + j];
    			char q = needle[j];
    			if (p == q)
    				j++;
    			else
    				break;
    		}
    		if (j == m)
    			return i;
    	}
    	return -1;
    }
};


int main() {
    Solution s;
    cout << s.strStr("abcde", "bc") << endl;
    
}
