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


/*iterate from left to right, and right to left

in the backward scan, the if-condition should be ratings[i] > ratings[i+1] && numbers[i] < numbers[i+1] + 1

without numbers[i] < numbers[i+1] + 1
we will fail in the case {4, 2, 3, 4, 1}: after the forward scan, numbers will become 1 1 2 3 1, 
then during backward scan, 3->2 since rating[3] = 4 > rating[4] = 1, so numbers[3] = numbers[4] + 1*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        int total = 0, n = ratings.size();
        vector<int> numbers(n, 0);
        numbers[0] = 1;
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i-1]) numbers[i] = numbers[i-1] + 1;
            else numbers[i] = 1;
        }
        printVector(numbers);
        total = numbers[n-1];
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1] && numbers[i] < numbers[i+1] + 1) numbers[i] = numbers[i+1] + 1;
            // if (ratings[i] > ratings[i+1]) numbers[i] = numbers[i+1] + 1; // fail
            total += numbers[i];
        }
        printVector(numbers);
        return total;
    }
};

int main() {
    Solution s;
    Examples eg;
    vector<int> ratings = {4, 2, 3, 4, 1};
    cout << s.candy(ratings) << endl;
}
