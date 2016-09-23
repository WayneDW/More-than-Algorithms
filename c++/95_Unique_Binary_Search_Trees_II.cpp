#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
    	int dp[n + 1] = {0};
    	dp[0] = 1;
    	for (int i = 1; i <= n; i++)
    		for (int j = 0; j < i; j++)
    			dp[i] += dp[j] * dp[i - 1 - j];
    	return dp[n];
    }
};



int main() {
	Solution s;
}