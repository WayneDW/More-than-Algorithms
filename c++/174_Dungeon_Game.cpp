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

/*The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. 
The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially 
positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health 
point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering 
these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's 
health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward 
or downward in each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he 
follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2 (K)  -3  3
-5  -10 1
10  30  -5 (P)

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right 
room where the princess is imprisoned.*/


/*   dp[i][j] represents the sum of path values from (0, 0) to (i, j)
     
     we need to keep track of values during the road for fear that the king may die
     dp_steps[i] represents the best values when the king take i steps
     Node: it takes us m + n - 2 steps from (0, 0) to (m-1, n-1), we need to consider 0 step 

*/

// class Solution {
// public:
//     int calculateMinimumHP(vector<vector<int> >& dungeon) {
//         int m = dungeon.size();
//         if (!m) return 0;
//         int n = dungeon[0].size();
//         if (!n) return 0;
//         // int dp[m][n] = {0};
//         vector<vector<int> > dp(m, vector<int>(n, 0));
//         vector<int> dp_steps(m + n - 1, INT_MIN);
//         dp[0][0] = dungeon[0][0];
//         for (int i = 1; i < m; i++) dp[i][0] = dp[i-1][0] + dungeon[i][0];
//         for (int j = 0; j < n; j++) dp[0][j] = dp[0][j-1] + dungeon[0][j];

//         // calc the damage from (0, 0) to (i, j)
//         for (int i = 1; i < m; i++) {
//             for (int j = 1; j < n; j++) {
//                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + dungeon[i][j];
//             }
//         }
//         // calc the minimum damage when we take k steps
//         for (int steps = 0; steps < m + n - 1; steps++) {
//             if (steps < n) iterate_matrix(steps, dp_steps, dp, 0, steps, m, n);
//             else iterate_matrix(steps, dp_steps, dp, steps - n + 1, n - 1, m, n);
//         }
//         int cnt_minimum = INT_MAX;
//         for (int v: dp_steps) cnt_minimum = min(v, cnt_minimum);
//         return 1 - cnt_minimum;
//     }

//     /*-->-->-->-->-->
//     * * * * * * * * |
//     * * * * * * * * v
//     * * * * * * * * |
//     * * * * * * * * v
//     * * * * * * * * X */
//     void iterate_matrix(int steps, vector<int> & dp_steps, vector<vector<int> > dp, int i, int j, int m, int n) {
//         if (i >= 0 && j >= 0 && i < m && j < n) {
//             dp_steps[steps] = max(dp_steps[steps], dp[i][j]);
//             iterate_matrix(steps, dp_steps, dp, i + 1, j - 1, m, n);
//         }        
//     }
// };


class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int> > hp(m+1, vector<int>(n+1, INT_MAX));
        hp[m-1][n] = hp[m][n-1] = 1;
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int need = min(hp[i+1][j], hp[i][j+1]) - dungeon[i][j];
                hp[i][j] = need <= 0? 1: need;
            }
        }
        return hp[0][0];
    }
};


int main() {
    Solution s;
    Examples eg;
    vector<vector<int> > dungeon = {{-2, -3, 3}, {-5, -10, 1}, {10, 30, -5}};
    cout << s.calculateMinimumHP(dungeon) << endl;
}
