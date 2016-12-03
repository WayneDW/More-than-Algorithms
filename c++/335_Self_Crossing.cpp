#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

/*            b                              b->x[i-4]
   +----------------+             +----------------+
   |                |             |                |
   |                |             |                | a->[i-5]
 c |                |   c->x[i-3] |                |
   |                | a           |                |    f->x[i]
   +----------->    |             |                | <----+
            d       |             |                |      | e->x[i-1]
                    |             |                       |
                                  +-----------------------+
                                               d->x[i-2]

    special case
      b
    +----
    |   |
  c |   | a
    |   |
    |   | e
    +----
      d

    1, d >= b and c <= a
    2, d >= b and c > a and b + f >= d and a + e >= c, don't forget e <= c
    special case:   b >= d
  */

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        for (int i = 3; i < x.size(); i++) {
            if (x[i] >= x[i-2] && x[i-1] <= x[i-3]) return true;
            if (i == 4 && x[i] + x[i-4] >= x[i-2] && x[i-1] == x[i-3]) return true;
            if (i >= 5 && x[i-2] >= x[i-4] && x[i-3] > x[i-5] && 
                x[i] + x[i-4] >= x[i-2] && x[i-5] + x[i-1] >= x[i-3] && x[i-1] <= x[i-3])
                return true;

        }
        return false;
    }
};


int main() {
    Solution s;
    Examples eg;
    vector<int> x;
    x.push_back(1);
    x.push_back(1);
    x.push_back(2);
    x.push_back(1);
    x.push_back(1);
    cout << s.isSelfCrossing(x) << endl;
}
