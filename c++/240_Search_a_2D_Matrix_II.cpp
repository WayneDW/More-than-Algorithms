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

/*Write an efficient algorithm that searches for a value in an m x n matrix. 
This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.
Given target = 20, return false.

Idea: first check the 1st row, we can know which column the target exists (if possible)
It fails in this case
{1, 2, 3, 4, 5},
{6, 7, 8, 9, 10}
{11,12,13,14,15}
{16,17,18,19,20}
{21,22,23,24,25}*/

class Solution_failed_version { // however we can update this to m log n version
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = matrix.size();
        if (!m) return false;
        int n = matrix[0].size();
        if (!n) return false;

        if (target < matrix[0][0] || target > matrix[m-1][n-1]) return false; // beyond range 
        // position the column
        int pos = binary_search_column(matrix[0], target);
        int top = 0, bot = m - 1, mid;
        cout << pos << endl;
        if (bot == 0) return matrix[0][pos] == target;
        if (matrix[top][pos] > target || matrix[bot][pos] < target) return false; 
        while (top <= bot) {
            mid = top + (bot - top) / 2;
            if (matrix[mid][pos] == target) return true;
            else if (matrix[mid][pos] < target) top = mid + 1;
            else bot = mid - 1;
        }
        return matrix[top][pos] == target;
    }
private:
    int binary_search_column(vector<int> vec, int target) {
        int left = 0, right = vec.size() - 1, mid, pos;
        while (left + 1 < right) {
            mid = left + (right - left) / 2;
            if (vec[mid] == target) {
                return mid;
            }
            else if (vec[mid] < target) left = mid;
            else right = mid;
        }
        if (vec[right] <= target) return right;
        else return left;
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (!m) return false;
        int n = matrix[0].size(), r = 0, c = n - 1;
        while (r < m && c >= 0) {
            if (matrix[r][c] == target) return true;
            if (matrix[r][c] > target) c--;
            else r++;
        }
        return false;
    } 
};

int main() {
    Solution s;
    Examples eg;
    // vector<vector<int> > matrix = {
    //   {1,   4,  7, 11, 15},
    //   {2,   5,  8, 12, 19},
    //   {3,   6,  9, 16, 22},
    //   {10, 13, 14, 17, 24},
    //   {18, 21, 23, 26, 30}};
    // vector<vector<int> > matrix = {{-1, 3}};
    // vector<vector<int> > matrix = {{1,4}, {2,5}};
    vector<vector<int> > matrix = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15},
        {16,17,18,19,20},
        {21,22,23,24,25}};
    cout << s.searchMatrix(matrix, 19) << endl;
}
