#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
    	int m = s.size();
    	int n = p.size();
    	vector<vector <bool> > dp;
    	// create one more dim to handle 0-dim easily
    	dp.resize(m + 1);
    	for (int i = 0; i < m + 1; i++)
    		dp[i].resize(n + 1, false);
    	// dp[i][j] means that s[0:i - 1] matches with p[0:j - 1]
    	dp[0][0] = true;
    	cout << m << " " << n << endl;
    	for (int i = 0; i <= m; i++) {
    		for (int j = 1; j <= n; j++) {
    			// can't judge * first in this code
    			if(p[j-1] != '.' && p[j-1] != '*') {
                    if(i > 0 && s[i-1] == p[j-1] && dp[i-1][j-1]){
                        dp[i][j] = true;
                        cout << i << " " << j << endl;
                    }
                }
    			else if (p[j - 1] == '.') {
    				if (i > 0 && dp[i - 1][j - 1])	{
    					dp[i][j] = true;
    					cout << i << " " << j << endl;
    				}
    			}
    			else if (j > 1) { // * cannot be the 1st element
    				if (dp[i][j - 1] || dp[i][j - 2]) {// * can match 0 | 1 element
    					dp[i][j] = true;
    					cout << i << " " << j << endl;
    				}
    				else if(i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]) {
    					dp[i][j] = true;
    					cout << i << " " << j << endl;
    				}
    			}
    		}
    	}
    	return dp[m][n];
    }
};

int main() {
    Solution s;
    cout << s.isMatch("ab", ".*c") << endl;


}
