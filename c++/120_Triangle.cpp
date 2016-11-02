#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include "func.cpp"

using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        int n = triangle.size();
        if (n == 0) return 0;
        else if (n == 1) return triangle[0][0];
        else if (n == 2) return min(triangle[1][0], triangle[1][1]) + triangle[0][0];
        int dp[2][n] = {0}, minP = INT_MAX;
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    dp[i%2][j] = dp[(i-1)%2][j>0?(j-1):j] + triangle[i][j];
                else
                    dp[i%2][j] = min(dp[(i-1)%2][j-1], dp[(i-1)%2][j]) + triangle[i][j];
                if (i == n - 1) minP = min(minP, dp[i%2][j]);
            }
        }
        //cout << dp[1][0] << " " << dp[1][1] << endl;
        return minP;
    }
};

int main() {
	Solution s;
    Examples eg;
    vector<int> res;
    res.push_back(2);
    vector<vector<int> > out;
    out.push_back(res);
    vector<int> res1;
    res1.push_back(3);
    res1.push_back(4);
    out.push_back(res1);
    vector<int> res2;
    res2.push_back(6);
    res2.push_back(5);
    res2.push_back(7);
    out.push_back(res2);

    cout << s.minimumTotal(out) << endl;
}
