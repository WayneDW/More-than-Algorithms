#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
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

/*Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

Example:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
Explanation:

Note:
The total number of elements of the given matrix will not exceed 10,000.*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0) return res;

        int m = matrix.size(), n = matrix[0].size(), i = 0, j = 0;
        int directions[2] = {-1, 1}, up_right = 1;

        for (int k = 0; k < m * n; k++) {
            res.push_back(matrix[i][j]);
            i += directions[0] * up_right;
            j += directions[1] * up_right;

            // should put these two conditions above j < 0, j < 0, because we have cases that match two cases at the same time, we should still do += 2
            if (i >= m) { i = m - 1; j += 2; up_right = -1 * up_right;} // when (m-1, j) -> (m, j-1), it is illegal, thus we change it to (m-1, j+1), j-1 + 2 = j+1
            if (j >= n) { j = n - 1; i += 2; up_right = -1 * up_right;} 

            if (i < 0) { i = 0; up_right = -1 * up_right;}
            if (j < 0) { j = 0; up_right = -1 * up_right;}
            
        }
        return res;
    }
};




int main() {
    Solution s;
    Examples eg;
}