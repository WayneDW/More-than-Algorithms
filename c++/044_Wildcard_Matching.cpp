#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
    	int i = 0, j = 0, sloc = 0, star = -1;
    	while (i < s.size()) {
    		if (j < p.size() && (s[i] == p[j] || p[j] == '?')) {
    			i++; j++;
    		}
    		else if (j < p.size() && (p[j] == '*')) {
    			star = j;
    			j++;
    			sloc = i;//
    		}
    		else if (star != -1) {
    			j = star + 1;
    			sloc++;
    			i = sloc;
    		}
    		else
    			return false;
    	}
    	while (j < p.size() and p[j] == '*')
    		j++;
    	if (j == p.size())
    		return true;
    	return false;
    }
};


int main() {
	Solution s;
	cout << s.isMatch("acacac", "ac*ac") << endl;
	cout << s.isMatch("aa", "a") << endl;
	cout << s.isMatch("ho", "ho**") << endl;

}
