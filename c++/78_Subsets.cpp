#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<int> part;
        vector<vector<int> > res;
        res.push_back(part);
        dfs(0, nums, part, res);
        return res;
    }

    void dfs(int start, vector<int> num, vector<int> part, vector<vector<int> > &res) {
    	if (num.size() == 0)
    		return;
    	for (int i = start; i < num.size(); i++) {
    		part.push_back(num[i]);
    		res.push_back(part);
    		dfs(i + 1, num, part, res);
    		part.pop_back();
    	}
    }
};


int main() {
	Solution s;
	int dat[] = {1,2,3};
	vector<int> num(dat, dat + 3);
	vector<vector<int> > res = s.subsets(num);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}
}