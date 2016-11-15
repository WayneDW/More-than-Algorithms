#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
        	for (int j = i + 1; j < matrix[i].size(); j++) {
        		int tmp = matrix[i][j];
        		matrix[i][j] = matrix[j][i];
        		matrix[j][i] = tmp;
        	}
        }
        for (int i = 0; i < matrix.size(); i++)
        	reverse(matrix[i].begin(), matrix[i].end());
        return matrix;
    }
};
