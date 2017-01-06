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


class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls(0), cows(0), cnt[10] = {0};
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) bulls++;
            else cnt[secret[i] - '0']++;
        }
        for (int i = 0; i < guess.size(); i++) {
            if (secret[i] == guess[i]) continue;
            if (cnt[guess[i] - '0'] > 0) {
                cnt[guess[i] - '0'] -= 1;
                cows++;
            }
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};

int main() {
    Solution s;
    Examples eg;
    cout << s.getHint("1807", "7810") << endl;
}
