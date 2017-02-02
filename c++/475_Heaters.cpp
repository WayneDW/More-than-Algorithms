#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

/*Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius to warm all the houses.

Now, you are given positions of houses and heaters on a horizontal line, find out minimum radius of heaters so that all houses 
could be covered by those heaters.

So, your input will be the positions of houses and heaters seperately, and your expected output will be the minimum radius standard of heaters.

Note:
Numbers of houses and heaters you are given are non-negative and will not exceed 25000.
Positions of houses and heaters you are given are non-negative and will not exceed 10^9.
As long as a house is in the heaters' warm radius range, it can be warmed.
All the heaters follow your radius standard and the warm radius will the same.
Example 1:
Input: [1,2,3],[2]
Output: 1
Explanation: The only heater was placed in the position 2, and if we use the radius 1 standard, then all the houses can be warmed.
Example 2:
Input: [1,2,3,4],[1,4]
Output: 1
Explanation: The two heater was placed in the position 1 and 4. We need to use radius 1 standard, then all the houses can be warmed.

[1,2,3,5,15]
[2,30]
Output:
13*/

/*One trick is used in the following idea, <= should be used instead of <
otherwise we fail in houses = [1,2] and heaters = [1,1,2], and end up with radius 1*/

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        if (heaters.size() == 0) return 0;

        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int idx = 0, res = 0;
        for (int i = 0; i < houses.size(); i++) {
            while (idx + 1 < heaters.size() && (abs(heaters[idx+1] - houses[i]) <= abs(heaters[idx] - houses[i]))) idx++;
            res = max(res, abs(heaters[idx] - houses[i]));
        }
        return res;
    }
};


int main() {
    Solution s;
    Examples eg;
    vector<int> houses{1,2,3,4}, heaters{1,4};
    cout << s.findRadius(houses, heaters) << endl;
}
