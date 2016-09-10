#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
    	vector<int> res;
    	int m = matrix.size();
    	if (m == 0)
    		return res;
    	int n = matrix[0].size();
    	int direction = 0;
    	int left = 0, right = n - 1;
    	int up = 0, down = m - 1;
    	while(true) {
    		if (direction == 0) { // up lane, go right
    			for (int i = left; i <= right; i++)
    				res.push_back(matrix[up][i]);
    			up++;
    		}
    		if (direction == 1) { // right lane, go down
    			for (int i = up; i <= down; i++)
    				res.push_back(matrix[i][right]);
    			right--;
    		}
    		if (direction == 2) { // bottom lane, go left
    			for (int i = right; i >= left; i--) 
    				res.push_back(matrix[down][i]);
    			down--;
    		}
    		if (direction == 2) { // left lane, go top
    			for (int i = down; i >= up; i--) 
    				res.push_back(matrix[i][left]);
    			left++;
    		}
    		if (left > right || up > down)
    			break;
    		direction = (direction + 1) % 4;
    	}
    	return res;
    }
};


int main() {
	
	int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	vector<vector<int> > matrix;
	for (int i = 0; i < 3; i++){
		vector<int> temp(mat[i], mat[i] + sizeof(mat[i]) / sizeof(int));
		matrix.push_back(temp);
	}
	Solution s;
	vector<int> res = s.spiralOrder(matrix);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;

}
