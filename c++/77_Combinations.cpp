#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
    	vector<int> res;
    	vector<vector<int> > result;
    	backtracking(1, k, n, res, result);
        return result;
    }
    void backtracking(int start, int k, int n, vector<int> res, vector<vector<int> > &result) {
		if (res.size() == k)
			result.push_back(res);
		for (int i = start; i < n + 1; i++) {
			res.push_back(i);
			backtracking(i + 1, k, n, res, result);
			res.pop_back(); // extremly important
		}
	}
};


int main() {
	Solution s;
	vector<vector<int> > result = s.combine(4, 2);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
}