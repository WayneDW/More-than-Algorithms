#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string lcp = "";
        if (strs.size() < 1)
        	return lcp;
        for (int i = 0; i < strs[0].size(); i++) {
        	for (int j = 1; j < strs.size(); j++) {
        		if (i > strs[j].size() || strs[0][i] != strs[j][i])
        			return lcp;
        	}
        	lcp.push_back(strs[0][i]);
        }
        return lcp;
    }
};


int main() {
    Solution s;
    vector<string> strs;
    strs.push_back("abc");
    strs.push_back("abd"); 
    cout << s.longestCommonPrefix(strs) << endl;
}
