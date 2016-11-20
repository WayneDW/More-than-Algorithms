#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& num, int target) {
    	vector<vector<int> > res;
    	vector<int> part;
    	sort(num.begin(), num.end());
    	res = dfs(num, target, 0, part, res);
    	// delete duplicates, TIME LIMIT EXCEEDED
    	/*
    	sort(res.begin(), res.end());
    	int i = 0;
    	vector<int> last;
    	
    	while (i < res.size()) {
    		if (last == res[i]){
    			res.erase(res.begin() + i);
    		}
    		else {
    			last = res[i];
    			i++;
    		}
    	}*/
        return res;
    }

    vector<vector<int> > dfs(vector<int> &num, int target, int start, vector<int> & part, vector<vector<int> > & res) {
    	if (target == 0)
    		res.push_back(part);

    	for (int i = start; i < num.size(); i++) {
    		if (num[i] > target)
    			break;
    		/***********************************************************
    		** Essential part, similar value only works for i == start
    		** otherwise, same value loops once
    		************************************************************/
    		if (i > start and num[i - 1] == num[i])
    			continue;
    		part.push_back(num[i]);
    		dfs(num, target - num[i], i + 1, part, res);
    		part.pop_back();
    	}
    	return res;
    }
};


int main() {
	Solution s;	
	int dat[] = {23,32,22,19,29,15,11,26,28,20,34,5,34,7,28,33,30,30,16,33,8,15,28,26,17,10,25,12,6,17,30,16,6,10,23,22,20,29,14,5,6,5,5,6,29,20,34,24,16,7,22,11,17,7,33,21,13,15,29,6,19,16,10,21,21,28,8,6};
	vector<int> vec(dat, dat + sizeof(dat) / sizeof(int));
	int target = 27;

	vector<vector<int> > res = s.combinationSum2(vec, target);
	for (int i = 0; i < res.size(); i++) {
		cout << "loop = ";
		for (int j = 0; j < res[i].size(); j++)
			cout << res[i][j] << " ";
		cout << endl;
	}


}
