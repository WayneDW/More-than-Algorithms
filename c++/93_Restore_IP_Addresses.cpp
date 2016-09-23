#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
    	vector<string> res;
    	if (s.size() > 12 or s.size() == 0)
    		return res;
    	string subStr;
    	dfs(s, 0, 0, subStr, res);
    	return res;
    }

    void dfs(string s, int idx, int pos, string subStr, vector<string> &res) {
    	if (idx > 3 or pos >= s.size())
    		return;
    	if (idx == 3 and pos >= s.size() - 3) {
    		//subStr += s[pos] + s[pos + 1] + s[pos + 2]; *** this part is wrong, the right is like a computation
    		if (pos == s.size() - 1 and isValid(s, pos, 1))
    			res.push_back(subStr + s[pos]);
    		else if (pos == s.size() - 2 and isValid(s, pos, 2)) {
    			for (int i = pos; i < s.size(); i++)
    				subStr.push_back(s[i]);
    			res.push_back(subStr);
    		}
    		else if (pos == s.size() - 3 and isValid(s, pos, 3)) {
    			for (int i = pos; i < s.size(); i++)
    				subStr.push_back(s[i]);
    			res.push_back(subStr);
    		}
    		return;
    	}
    	if (isValid(s, pos, 1))
    		dfs(s, idx + 1, pos + 1, subStr + s[pos] + '.', res);
    	if (isValid(s, pos, 2))
    		dfs(s, idx + 1, pos + 2, subStr + s[pos] + s[pos + 1] + '.', res);
   		if (isValid(s, pos, 3))
   			dfs(s, idx + 1, pos + 3, subStr + s[pos] + s[pos + 1] + s[pos + 2] + '.', res);
    }
    bool isValid(string s, int pos, int len) {
    	if (len == 1 and pos < s.size())
    		return 1;
    	else if (len == 2 and pos + 1 < s.size() and s[pos] != '0')
    		return 1;
    	else if (len == 3 and pos + 2 < s.size() and s[pos] != '0') {
    		if ((s[pos] - '0') * 100 + (s[pos + 1] - '0') * 10 + s[pos + 2] - '0' < 256)
    			return 1;
    	}
    	return 0;
    }
};


int main() {
	Solution s;
	//vector<string> res = s.restoreIpAddresses("25525511135");
	//vector<string> res = s.restoreIpAddresses("1111");
	//vector<string> res = s.restoreIpAddresses("010010");
	vector<string> res = s.restoreIpAddresses("172162541");
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << endl;
}