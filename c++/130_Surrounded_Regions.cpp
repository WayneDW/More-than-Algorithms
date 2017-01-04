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

/*Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X*/


/*1. check the boarder of the matrix, set O and its neighbors as 1
  2. recover 1 as O
  3. take care of stack overflow when the recursion happens too many times
  This question is better solved by BFS due to stack overflow, due to my limited time, just give the dfs version
  https://discuss.leetcode.com/topic/2982/my-bfs-solution-c-28ms*/

class Solution {
public:
    void solve(vector<vector<char> >& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        if (n == 0) return;

        for (int i = 0; i < m; i++) { // set the left and right-most cols
            set_as_1(board, i, 0, m, n);
            if (n > 1) set_as_1(board, i, n - 1, m, n);
        }

        for (int i = 0; i < n; i++) { // set the top and bot rows 
            set_as_1(board, 0, i, m, n);
            if (m > 1) set_as_1(board, m - 1, i, m, n);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X'; // the order matters
                if (board[i][j] == '1') board[i][j] = 'O';
            }
        }
    }

    void set_as_1(vector<vector<char> >& board, int i, int j, int m, int n) {
        if (i >= 0 && j >= 0 && i < m && j < n && board[i][j] == 'O') {
            board[i][j] = '1';
            set_as_1(board, i + 1, j, m, n);
            set_as_1(board, i - 1, j, m, n);
            
            if (j > 1) set_as_1(board, i, j - 1, m, n); // avoid stack overflow
            set_as_1(board, i, j + 1, m, n);
        }
    }
};
