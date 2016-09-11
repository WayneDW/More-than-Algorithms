#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
    	int m = matrix.size();
    	int n = matrix[0].size();
    	int tagRow[m] = {0};
    	int tagCOl[n] = {0};
    	for (int i = 0; i < m; i++) {
    		for (int j = 0; j < n; j++) {
    			if (matrix[i][j] != 0)
    				continue;
    			tagRow[i] = 1;
    			tagCOl[j] = 1;
    		}
    	}
    	for (int i = 0; i < m; i++)
    		for (int j = 0; j < n; j++)
    			if (tagRow[i] || tagCOl[j])
    				matrix[i][j] = 0;    
    }
};

// there is actually a better way which uses o(1) space
// the trick is to mark infos in the first row and col


int main() {
	Solution s;
}