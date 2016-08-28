#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
    	int n = nums.size();
    	vector<vector<int> > res;
    	if (n <= 1) {
    		res.push_back(nums);
    		return res;
    	}
    	for (int i = 0; i < n; i++) {
    		vector<vector<int> > tmp;
    		vector<int> copy = nums;
    		copy.erase(copy.begin() + i);

    		tmp = permute(copy);
    		for (int j = 0; j < tmp.size(); j++) {
    			tmp[j].push_back(nums[i]);
    			res.push_back(tmp[j]);
    		}
    	}
        return res;
    }
};


int main() {
	Solution s;
	int dats[] = {0, 1, 2};
	vector<int> dat(dats, dats + sizeof(dats) / sizeof(int));
	vector<vector<int> > res = s.permute(dat);

	cout << "-----------------------" << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << "-----------------------" << i << " ......" << endl;
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}
