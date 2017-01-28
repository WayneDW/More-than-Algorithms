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

/*For a web developer, it is very important to know how to design a web page's size. So, given a specific
rectangular web page’s area, your job by now is to design a rectangular web page, whose length L and width 
W satisfy the following requirements:

1. The area of the rectangular web page you designed must equal to the given target area.

2. The width W should not be larger than the length L, which means L >= W.

3. The difference between length L and width W should be as small as possible.
You need to output the length L and the width W of the web page you designed in sequence.
Example:
Input: 4
Output: [2, 2]
Explanation: The target area is 4, and all the possible ways to construct it are [1,4], [2,2], [4,1]. 
But according to requirement 2, [1,4] is illegal; according to requirement 3,  [4,1] is not optimal compared 
to [2,2]. So the length L is 2, and the width W is 2.
Note:
The given area won't exceed 10,000,000 and is a positive integer
The web page's width and length you designed must be positive integers.*/

class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<vector<int>> res;
        int last = INT_MAX;
        for (int i = 1; i <= area; i++) {
            if (area % i != 0) continue;
            int l = area / i;
            int diff = l - i;
            if (diff >= 0 && diff < last) {
                res.push_back(vector<int>{l, i});
            }
            if (l < i) break;
            last = diff;
        }
        return res.back();
    }
};



int main() {
    Solution s;
    Examples eg;
    print(s.constructRectangle(5));
}
