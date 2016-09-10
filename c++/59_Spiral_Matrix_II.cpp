#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;


class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
    	vector<vector<int> > res(n, vector<int>(n)); // initialize 2-d vector

    	int left = 0, top = 0;
    	int right = n - 1, down = n - 1;
    	int direction = 0;
    	int number = 1;
    	while (1) {
    		if (direction == 0) {
    			for (int i = left; i <= right; i++)
    				res[top][i] = number++;
    			top++;
    		}
    		if (direction == 1) {
    			for (int i = top; i <= down; i++)
    				res[i][right] = number++;
    			right--;
    		}
    		if (direction == 2) {
    			for (int i = right; i >= left; i--)
    				res[down][i] = number++;
    			down--;
    		}
    		if (direction == 3) {
    			for (int i = down; i >= top; i--)
    				res[i][left] = number++;
    			left++;
    		}
    		if (number == pow(n, 2) + 1)
    			break;
    		direction = (direction + 1) % 4;
    	}
    	return res;
    }
};


int main() {
	Solution s;
	vector<vector<int> > res = s.generateMatrix(3);

}