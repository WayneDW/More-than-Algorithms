#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public: // dp[i] : sum of maximum value ended at i
    int maxSubArray(vector<int>& num) {
    	int n = num.size();
    	if (n == 0)
    		return NULL;
    	int maxS = num[0];
    	int dp[n] = {0};
    	dp[0] = num[0];
    	for (int i = 1; i < n; i++){
    		dp[i] = dp[i - 1] > 0 ? dp[i - 1] + num[i] : num[i];
    		maxS = max(maxS, dp[i]);
    	}
    	return maxS;
    }
};

