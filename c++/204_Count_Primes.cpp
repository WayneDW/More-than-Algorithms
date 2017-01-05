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

/* Count the number of prime numbers less than a non-negative number, n.
// iterate all the 4,  6, 8 10 12 ... 30
                   9  12 15 18 21 ... 30
                   25 30 
                   10 */

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n, true);
        prime[0] = false, prime[1] = false;
        for (int i = 2; i < sqrt(n); ++i) {
            if (prime[i]) {
                for (int j = i*i; j < n; j += i) {
                    prime[j] = false;
                    // cout << j << " " << prime[j] << " ";
                }    
                // cout << endl;
            }    
        }
        return count(prime.begin(), prime.end(), true);
    }
};

int main() {
    Solution s;
    Examples eg;
    cout << s.countPrimes(31) << endl;
}
