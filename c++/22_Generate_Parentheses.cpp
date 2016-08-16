#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;

// reference: 
// http://bangbingsyb.blogspot.com/2014/11/leetcode-generate-parentheses.html

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> allCombo;
    	string combo;
    	backTracking(n, 0, 0, combo, allCombo);
    	return allCombo;

    }
    void backTracking(int n, int left, int right, string combo, vector<string> &allCombo) {
    	
    	if (left == n && right == n) {
    		allCombo.push_back(combo);
    		return;
    	}
    	if (left < n) {
    		//combo += '(';
    		combo.push_back('(');
    		backTracking(n, left + 1, right, combo, allCombo);
    		combo.pop_back();
    	}
    	if (right < left) {
    		combo.push_back(')');
    		backTracking(n, left, right + 1, combo, allCombo);
    		combo.pop_back();
    	}
    }    
};

int main() {
    Solution s;
    vector<string> res;
    res = s.generateParenthesis(3);
    for (int i = 0; i < res.size(); i++)
    	cout << res[i] << " ";
    cout << endl;
    
}
