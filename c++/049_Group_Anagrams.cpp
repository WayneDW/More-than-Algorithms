#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

/*
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]*/

class Solution {
public:
	
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	map<string, vector<string> > dt;

    	for (int i = 0; i < strs.size(); i++) {
    		string sortedWord = strs[i];
    		sort(sortedWord.begin(), sortedWord.end());
    		dt[sortedWord].push_back(strs[i]);
    	}

    	vector<vector<string> > res;
    	for (map<string, vector<string> >::iterator it = dt.begin(); it != dt.end(); it++) {
    		res.push_back(it->second);
    	}
        return res;
    }
};


int main() {
	Solution s;
	string ss[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<string> vecS(ss, ss + 6);
	vector<vector<string> > res;
	res = s.dgroupAnagrams(vecS);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}


}
