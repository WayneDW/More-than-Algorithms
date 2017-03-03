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

/*Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]],
k = 8,

return 13.
Note: 
You may assume k is always valid, 1 ≤ k ≤ n2.*/

class Solution_binary_search { // idea is easy but hard corner case to implement
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0], right = matrix[n - 1][n - 1];
        int mid = 0;
        while (left < right) {
            int pos = 0;
            mid = left + (right - left) / 2;
            for (int i = 0; i < n; i++) {
                pos += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            cout << left << " " << mid << " " << right << endl;
            if (pos < k) left = mid + 1;
            else right = mid;
        }
        return left;
    }
};

class Solution_priority_queue { // eaiser to implement once you know how to do it
public:
    struct cmp {
        bool operator() (const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b) {
            return a.first > b.first;
        }
    };
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>,cmp> q;
        for (int j = 0; j < m; j++)
            q.push(make_pair(matrix[0][j], make_pair(0, j)));

        int res;
        while (k--) {
            res = q.top().first;
            int i = q.top().second.first;
            int j = q.top().second.second;
            q.pop();
            if (i < m - 1)
                q.push(make_pair(matrix[i+1][j], make_pair(i+1,j)));
        }
        return res;
    }
}

int main() {
    Solution s;
    Examples eg;
    vector<vector<int>> matrix = {{1,5,9}, {10,11,13}, {12,13,15}};
    cout << s.kthSmallest(matrix, 8) << endl;
}
