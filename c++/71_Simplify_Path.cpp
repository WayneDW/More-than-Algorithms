#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
    	string res, part;
    	vector<string> vec;
    	path.push_back('/');
    	for (int i = 0; i < path.size(); i++) {
    		if (path[i] != '/')
    			part.push_back(path[i]);
    		else if (path[i] == '/') {  			
    			if (part.empty())
    				continue;
    			else if (part == "..") {
    				if (vec.empty()) {
    					part.clear();
    					continue;
    				}
    				vec.pop_back();
    			}
    			else if (part != ".")
    				vec.push_back(part);
    			part.clear();
    		}
    	}

		for (int i = 0; i < vec.size(); i++) {
    		res += "/" + vec[i];
    	}
    	if (res.empty())
    		res = "/";
    	return res;
    }
};


int main() {
	Solution s;
	cout << s.simplifyPath("/home/../../..") << endl;
}