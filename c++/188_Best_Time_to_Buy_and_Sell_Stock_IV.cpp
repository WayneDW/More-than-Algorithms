#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

/*Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).*/

/*
    suppose k = 2 (in this case, it is the same as 131), initially we have 0 money
    buy 1st stock, we have max(buy[1], -prices[i])
    sell 1st stock, we have the max(sell[1], buy[1] + prices[i])
    buy 2nd, we have the max(buy[2], sell[1] - prices[i])
    sell 2nd, we get the max(sell[2], buy[2] + prices[i])
*/

/*Inspired by weijiac in Best Time to Buy and Sell Stock III
  https://leetcode.com/discuss/18330/is-it-best-solution-with-o-n-o-1*/


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0) return 0;
        if (k > prices.size() / 2) {
            int sum = 0;
            for (int i = 1; i < prices.size(); i++)
                sum += max(prices[i] - prices[i-1], 0);
            return sum;
        }

        vector<int> buy(k, INT_MIN);
        vector<int> sell(k, 0);
        for (int i = 0; i < prices.size(); i++) {
            for (int j = 0; j < k; j++) {
                if (j == 0) buy[j] = max(buy[j], -prices[i]);
                else buy[j] = max(buy[j], sell[j-1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k - 1];
    }
};

// another idea is to use stack and heap
// https://discuss.leetcode.com/topic/9522/c-solution-with-o-n-klgn-time-using-max-heap-and-stack

int main() {
    Solution s;
    Examples eg;
    vector<int> prices;
    cout << s.maxProfit(3, prices) << endl;
}
