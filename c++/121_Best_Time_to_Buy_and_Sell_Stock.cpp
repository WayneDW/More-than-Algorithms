#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

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
