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
122. Best Time to Buy and Sell Stock II
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions 
as you like (ie, buy one and sell one share of the stock multiple times). However, you 
may not engage in multiple transactions at the same time (ie, you must sell the stock 
before you buy again).
*/

// as long as profit comes, add to total profit.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            int last = prices[i - 1];
            if (prices[i] > last)
                profit += prices[i] - last;
        }
        return profit;
    }
};