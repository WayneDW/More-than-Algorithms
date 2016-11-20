#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


class Solution {
public:
    void solveSudoku(vector<vector<char> >& board) {
    	if (board.size() == 9 || board[0].size() == 9)
    		bool tag = solver(board, 0, 0);
    }

    bool solver(vector<vector<char> > &board, int i, int j) {
    	if (i == 9)
    		return true;
    	int row, col;
    	if (j == 8) {
    		row = i + 1;
    		col = 0;
    	}
    	else{
    		row = i;
    		col = j + 1;
    	}

    	if (board[i][j] != '.') {
    		if (!isValidSudoku(board, i, j))
    			return false;
    		return solver(board, row, col);
    	}
    	// if board is ., iterate from 1 to 9
    	for (int k = 1; k <= 9; k++) {
    		board[i][j] = k + '0';
    		if (isValidSudoku(board, i, j) && solver(board, row, col))
    			return true;
    	}
    	// false occurs, reset all values
    	board[i][j] = '.';
    	return false;
    }

    // don't use question 36 directly due to endless waste of computation
    bool isValidSudoku(vector<vector<char> > &board, int irow, int icol) {
        char val = board[irow][icol];
        
        // check row & col
        for(int i = 0; i < 9; i++)
            if ((board[irow][i] == val && i != icol) || (board[i][icol] == val && i != irow))
            	return false;
        
        //check 3x3 box
        int irow0 = irow / 3 * 3;
        int icol0 = icol / 3 * 3;
        for(int i = irow0; i < irow0 + 3; i++) {
            for(int j = icol0; j < icol0 + 3; j++) {
                if(board[i][j] == val && (i != irow || j != icol))
                	return false;
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
	s.solveSudoku(board);
}