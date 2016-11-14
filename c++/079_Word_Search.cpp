#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
    	if (board.size() == 0 || board[0].size() == 0)
    		return false;
    	int m = board.size(), n = board[0].size();
    	vector<vector<bool> > track(m, vector<bool> (n, false));
    	for (int i = 0; i < m; i++) {
    		for (int j = 0; j < n; j++) {
    			if (dfs(board, i, j, m, n, 0, word, track))
    				return true;
    		}
    	}
    	return false;
    }

    bool dfs(vector<vector<char> >& board, int i, int j, int m, int n, int index, string word, vector<vector<bool> > &track) {
    	if (index == word.size())
    		return true;
    	if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index] || track[i][j])
    		return false;
    	track[i][j] = 1;
    	// classical part
    	if (dfs(board, i + 1, j, m, n, index + 1, word, track)) return true;
    	if (dfs(board, i - 1, j, m, n, index + 1, word, track)) return true;
    	if (dfs(board, i, j + 1, m, n, index + 1, word, track)) return true;
    	if (dfs(board, i, j - 1, m, n, index + 1, word, track)) return true;
    	track[i][j] = 0; // hard part
    	return false;
    }
};


int main() {
	Solution s;
	vector<vector<char> > board;
	string word;
	bool tag =s.exist(board, word);
}