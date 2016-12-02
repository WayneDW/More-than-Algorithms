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

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */


class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int n = points.size(), res = 0;      
        for (int i = 0; i < n; i++) {
            int isame, iver, maxN;
            maxN = isame = iver = isame = 0;
            unordered_map<float, int> dt;
            for (int j = i + 1; j < n; j++) {
                if (points[i].x == points[j].x) {
                    if (points[i].y == points[j].y)
                        isame++;
                    else
                        iver++; // slope being infinity
                    maxN = max(maxN, iver);
                }
                else {
                    float slope = (float)(points[j].y - points[i].y)/ (float)(points[j].x - points[i].x);
                    dt[slope] += 1;
                    maxN = max(maxN, dt[slope]);
                }
            }
            res = max(res, maxN + isame + 1); // may have some same points, we need to consider isame
        }
        return res;
    }
};

int main() {
    Solution s;
    Examples eg;
}
