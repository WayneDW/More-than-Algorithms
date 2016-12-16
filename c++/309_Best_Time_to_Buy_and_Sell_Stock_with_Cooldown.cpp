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

/*prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]*/


/*buy[i]: money at i when we buy
sell[i]: money at i when we sell
reset[i]: money at i when we wait, here reset[i] = sell[i-1]

buy[i] = max(buy[i-1], reset[i-1] - price[i]) = max(buy[i-1], sell[i-2] - price[i])
sell[i] = max(sell[i-1], buy[i-1] + price[i])*/

class Solution_v1 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        vector<int> buy(n, INT_MIN);
        vector<int> sell(n, 0);
        vector<int> wait(n, 0);
        buy[0] = -prices[0];
        for (int i = 1; i < n; i++) {
            wait[i] = max(sell[i-1], buy[i-1]);
            buy[i] = max(buy[i-1], wait[i-1] - prices[i]);
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
            
        }
        return max(sell[n-1], wait[n-1]);
    }
};

class Solution_v2 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        vector<int> buy(n, INT_MIN);
        vector<int> sell(n, 0);
        buy[0] = -prices[0];
        int wait = 0;
        for (int i = 1; i < n; i++) {
            buy[i] = max(buy[i-1], wait - prices[i]);
            wait = max(sell[i-1], buy[i-1]);
            sell[i] = max(sell[i-1], buy[i-1] + prices[i]);
            
        }
        return max(sell[n-1], wait);
    }
};

class Solution_v3 {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        int buy = -prices[0], wait = 0, sell = 0;
        for (int i = 1; i < n; i++) {
            buy = max(buy, wait - prices[i]);
            wait = max(sell, buy);
            sell = max(sell, buy + prices[i]);
            
        }
        return max(sell, wait);
    }
};


int main() {
    Solution s;
    Examples eg;
}
