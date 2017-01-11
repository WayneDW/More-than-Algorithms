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

/*According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular 
automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts
 with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population. (1)
Any live cell with two or three live neighbors lives on to the next generation. (2)
Any live cell with more than three live neighbors dies, as if by over-population.. (3)
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction. (4)
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells
 first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems 
when the active area encroaches the border of the array. How would you address these problems?*/


/*Trick 1: although we use int, we only need 1 bit of int, thus we use 1st bit as the current state, 2nd bit as the next state
  Trick 2: the 2nd state is originally 0, we only care about when it becomes 1, thus (2)(4) are the condition */

class Solution {
public:
    void gameOfLife(vector<vector<int> >& board) {
        int m = board.size();
        for (int i = 0; i < m; i++) {
            int n = board[0].size();
            for (int j = 0; j < n; j++) {
                // get the number of the neighbors of a cell
                int no_neigh = 0;
                for (int i_ = max(i - 1, 0); i_ <= min(i + 1, m - 1); i_++) {
                    for (int j_ = max(j - 1, 0); j_ <= min(j + 1, n - 1); j_++) {
                        no_neigh += board[i_][j_] & 1; // & 1 is necessary: when 00->10, some cell may have neighbors 10, and we need 0
                    }
                }
                no_neigh -= board[i][j] & 1;
                // life condition 2, 4
                if (board[i][j] == 1 && no_neigh >= 2 && no_neigh <= 3) board[i][j] = 3; // make it 11
                if (board[i][j] == 0 && no_neigh == 3) board[i][j] = 2; // make it 10
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < board[0].size(); j++) {
                board[i][j] >>= 1; // move the state forward which is also move 2nd state to the 1st state
            }
        }
    }
};


int main() {
    Solution s;
    Examples eg;
}
