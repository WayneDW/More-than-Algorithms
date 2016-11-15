#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> allCombo;
    	string combo;
    	backTracking(n, 0, 0, combo, allCombo);
    	return allCombo;

    }
    // passing by reference, be sure to change allCombo
    void backTracking(int n, int left, int right, string combo, vector<string> &allCombo) {
    	
    	if (left == n && right == n)
    		allCombo.push_back(combo);
    	if (left < n)
    		backTracking(n, left + 1, right, combo  + '(', allCombo);
    	if (right < left)
    		backTracking(n, left, right + 1, combo + ')', allCombo);
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
