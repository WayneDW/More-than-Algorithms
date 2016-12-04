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
                
/*
        Example:
        X..X
        ...X
        ...X
        In the above board there are 2 battleships.
        Invalid Example:
        ...X
        XXXX
        ...X
        This is an invalid board that you will not receive 
        - as battleships will always have a cell separating between them.
*/


class Solution_extra_space {
public:
    int loop[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int countBattleships(vector<vector<char> >& board) {
        if (!board.size() || !board[0].size()) return 0;
        int m = board.size(), n = board[0].size(), cnt = 0;
        vector<vector<bool> > ifVisited(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!ifVisited[i][j] && board[i][j] == 'X') {
                    cnt++;
                    cnt_ships(i, j, m, n, ifVisited, board);
                }
                
            }
        }
        return cnt;
    }

    void cnt_ships(int i, int j, int m, int n, vector<vector<bool> > &ifVisited, vector<vector<char> >& board) {
        if (i >= 0 && i < m && j >= 0 && j < n && !ifVisited[i][j] && board[i][j] == 'X') {
            ifVisited[i][j] = true;
            for (auto pair: loop) cnt_ships(i + pair[0], j + pair[1], m, n, ifVisited, board);
        }
    }

};

class Solution {
public:
    int countBattleships(vector<vector<char> >& board) {
        if (!board.size() || !board[0].size()) return 0;
        int m = board.size(), n = board[0].size(), cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != 'X') continue;
                else if (i > 0 && board[i-1][j] == 'X') continue;
                else if (j > 0 && board[i][j-1] == 'X') continue;
                cnt++;
            }
        }
        return cnt;
    }
};


int main() {
    Solution s;
    Examples eg;
    vector<char> a1 = {'X', '.', '.', 'X'};
    vector<char> a2 = {'.', 'X', '.', 'X'};
    vector<char> a3 = {'.', '.', '.', 'X'};
    vector<vector<char> > res = {a1, a2, a3};
    cout << s.countBattleships(res) << endl;

}
