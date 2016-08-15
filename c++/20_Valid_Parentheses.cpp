#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;

        for (int i = 0; i < s.size(); i++) {
        	if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        		stk.push(s[i]);
        	else {
        		if (stk.empty() || unmatch(stk.top(), s[i]))
        			return false;
        		stk.pop();
        	}
        }
        return stk.empty();
    }
    bool unmatch(char a, char b) {
    	if (a == '(')
    		return (b != ')');
    	else if (a == '[')
    		return (b != ']');
    	else if (a == '{')
    		return (b != '}');
    	else
    		return false;
    }
};


int main() {
    Solution s;
    
}
