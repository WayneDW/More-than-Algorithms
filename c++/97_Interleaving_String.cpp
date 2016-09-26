#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
    	int m = s1.size(), n = s2.size();
    	if (m + n != s3.size())
    	    return false;
    	int dp[m + 1][n + 1] = {0};
    	dp[0][0] = true;
    	for (int i = 0; i < m; i++)
    		if (s1[i] == s3[i] and dp[i][0])
    			dp[i + 1][0] = true;
    	for (int i = 0; i < n; i++)
    		if (s2[i] == s3[i] and dp[0][i])
    			dp[0][i + 1] = true;
    	for (int i = 0; i < m; i++) {
    		for (int j = 0; j < n; j++) {
    			if (s3[i + j + 1] == s1[i] and dp[i][j + 1])
    				dp[i + 1][j + 1] = dp[i][j + 1];
    			else if (s3[i + j + 1] == s2[j] and dp[i + 1][j])
    				dp[i + 1][j + 1] = dp[i + 1][j];
    		}
    	}
    	return dp[m][n];
        
    }
};