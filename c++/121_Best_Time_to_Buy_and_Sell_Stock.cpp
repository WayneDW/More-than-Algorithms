#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

/*
Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX, profit = 0;
        for (int i = 0; i < prices.size(); i++) {
            if (minPrice > prices[i])
                minPrice = prices[i];
            profit = max(profit, prices[i] - minPrice);
        }
        return profit;
    }
};


int main() {
	Solution s;
}
