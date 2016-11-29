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

/*
       1101
+      0101
=     10010

a^b  = 1000
a&b<1= 1010 

a^b  =   10
a&b<1=10000

a^b  =10010
a&b<1=    0

sum = 10010

In summary, 
^ takes the unique digit that does not have carry potential
skip 0 vs 0, 1 vs 1, only consider 0 vs 1 and 1 vs 0
& takes the same 1 and get the function of multiplication
only consider 1 vs 1, if multiply by 2 when it occurs to us


Another question is that why in this code, it only considers the terminating case of b==0
In fact, 
if we sum 
        111
        111

a^b     000
a&b    1110

a^b    1110
a&b       0

sum =  1110
*/
class Solution {
public:
    int getSum(int a, int b) {
        return b==0? a: getSum(a^b, (a&b)<<1); //be careful about the terminating condition;
    }
};

int main() {
	Solution s;
    Examples eg;
    cout << s.count_one(7) << endl;
}
