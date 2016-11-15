#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& num, int target) {
        vector<int> part;
        vector<vector<int> >res;
        sort(num.begin(), num.end());
        res = dfs(num, 0, target, part, res);
        return res;
    }
    // pass by reference, important, otherwise change nothing
    vector<vector<int> > dfs(vector<int> &num, int start, int target, vector<int> &part, vector<vector<int> > &res) {
    	if (target == 0)
    		res.push_back(part);
    	int n = num.size();
    	for (int i = start; i < n; i++) {
    		if (num[i] > target)
    			break;
    		part.push_back(num[i]);
    		dfs(num, i, target - num[i], part, res);
    		// difference with python, need to recover part
    		part.pop_back();
    	}
    	return res;
    }
};


int main() {
	Solution s;	
	int dat[] = {2, 3, 6, 7};
	vector<int> vec(dat, dat + sizeof(dat) / sizeof(int));
	int target = 7;

	vector<vector<int> > res = s.combinationSum(vec, target);
	for (int i = 0; i < res.size(); i++) {
		cout << "loop = " << i << " ";
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}
