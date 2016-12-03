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

 A        C
 |--------|
      E        G  
      |--------|

 C        A
 |--------|
      E        G  
      |--------|

 C        A
 |--------|
      G        E  
      |--------|

 A        C
 |--------|
      E        G  
      |--------|
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int total = (C-A) * (D-B) + (G-E) * (H-F);
        if (C <= E || A >= G || D <= F || B >= H)
            return total;
        else {
            int t[4] = {A, C, E, G};
            vector<int> X(t, t+4);
            sort(X.begin(), X.end());
            int p[4] = {B, D, F, H};
            vector<int> Y(p, p+4);
            sort(Y.begin(), Y.end());
            return total - (X[2] - X[1]) * (Y[2] - Y[1]);
        }
    }
};


int main() {
    Solution s;
    Examples eg;
    cout << s.computeArea(1,2,3,4,5,6,7,8) << endl;
}
