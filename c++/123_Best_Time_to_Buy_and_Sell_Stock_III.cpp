#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;
/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock 
before you buy again).*/


/* Split the problem into two parts, maxProfit = max{maxProfit[:i] + maxProfit[i+1:]}*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // split into two parts
        int n = prices.size();
        if (n == 0) return 0;
        int minL = INT_MAX;
        int maxPL = 0, profitL[n] = {0};
        int maxR = 0, maxPR = 0, profit = 0;
        for (int i = 0; i < n; i++) {
            if (prices[i] < minL)
                minL = prices[i];
            else
                maxPL = max(maxPL, prices[i] - minL);
            profitL[i] = maxPL;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (prices[i] > maxR)
                maxR = prices[i];
            else
                maxPR = max(maxPR, maxR - prices[i]);
            profit = max(profit, maxPR + profitL[i]);
        }
        return profit;
    }
};


int main() {
	Solution s;
    vector<int> prices;
    prices.push_back(1);
    prices.push_back(5);
    cout << s.maxProfit(prices) << endl;
}
