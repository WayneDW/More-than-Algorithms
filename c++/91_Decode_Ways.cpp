#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
    	int n = s.size();
    	if (n == 0 or s[0] == '0')
    		return 0;
    	int dp[n + 1] = {0};
    	dp[0] = 1;
    	dp[1] = 1;

    	for (int i = 2; i <= n; i++) {
    		int fake_int = 10 * (s[i - 2] - '0') + s[i - 1] - '0';
    		// last 2 digits makes an integer between (10, 26] / 20
    		if (fake_int > 10 and fake_int <= 26 and fake_int != 20) 
    			dp[i] = dp[i - 1] + dp[i - 2];
    		else if (fake_int == 10 or fake_int == 20) // last 2 are 10 or 20
    			dp[i] = dp[i - 2];
    		else if (s[i - 1] != '0') // ***** important condition
    			dp[i] = dp[i - 1];
    		else
    			return 0;
    	}
    	return dp[n];
    }
};


int main() {
	Solution s;
	cout << s.numDecodings("100") << endl;
}