#include <iostream>
#include <vector>
#include <map>
#include <set>
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

/*A city's skyline is the outer contour of the silhouette formed by all the buildings in that 
city when viewed from a distance. Now suppose you are given the locations and height of all the 
buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed 
by these buildings collectively (Figure B).

https://leetcode.com/static/images/problemset/skyline1.jpg

The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], 
where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, 
and Hi is its height. It is guaranteed that 0 ≤ Li, Ri ≤ INT_MAX, 0 < Hi ≤ INT_MAX, and Ri - Li > 0. 
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], 
[5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], 
[x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal 
line segment. Note that the last key point, where the rightmost building ends, is merely used to 
mark the termination of the skyline, and always has zero height. Also, the ground in between any 
two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], 
[15 10], [20 8], [24, 0] ].*/


/*  The graphical explanation is shown in 
    briangordon.github.io/2014/08/the-skyline-problem.html
    The core idea is sliding a vertical line from left to right,
    if it is the left of a rectangle, push the value into a multiset, 
    otherwise, pop it outside; get the maximum value in the multiset */


class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        multimap<int, int> coords;
        for (auto building : buildings) {
            coords.emplace(building[0], building[2]);
            coords.emplace(building[1], -building[2]);
        }

        multiset<int> heights = { 0 };
        vector<pair<int, int>> corners;
        int x = -1;
        int y = 0;
        for (auto p : coords) {
             if ((x >= 0) && (p.first != x) && (corners.empty() || (corners.back().second != y))) {
                corners.push_back(pair<int, int> (x, y));
            }
            if (p.second >= 0) {
                heights.insert(p.second); // encounter the left of rectangle, push height into data structure
            }
            else {
                heights.erase(heights.find(-p.second)); // encounter the right part, pop the height outside.
            }

            x = p.first; // the x coordinate
            y = *heights.rbegin(); // the biggest height

        }
        
        if (!corners.empty()) corners.emplace_back(x, 0); // c++11 new function
        return corners;
    }
};


int main() {
    Solution s;
    Examples eg;
    vector<vector<int> > buildings = {{2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8}}; 
    vector<pair<int, int> > res = s.getSkyline(buildings);
    print(res);
}
