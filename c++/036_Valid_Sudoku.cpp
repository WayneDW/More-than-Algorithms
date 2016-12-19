#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char> > & board) {
        if (board.size() != 9 or board[0].size() != 9) return false;
        unordered_map<int, map<char, bool> > row, col, grid;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;
                int num = i / 3 * 3 + j / 3;
                if (row[i].count(board[i][j]) > 0 || col[j].count(board[i][j]) > 0 || grid[num].count(board[i][j]) > 0) return false;
                row[i][board[i][j]] = 0;
                col[j][board[i][j]] = 0;
                grid[num][board[i][j]] = 0;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<char> > board;
    string str[] = {"7...4....","...865...",".1.2.....",".....9...","....5.5..",".........","......2..",".........","........."};

    // useful way to assign values to 2D vector
    for (int i = 0; i < 9; i++) {
        vector<char> tmp;
        for (int j = 0; j < 9; j++)
            tmp.push_back(str[i][j]);
        board.push_back(tmp);
    }
    cout << s.isValidSudoku(board) << endl;
}
