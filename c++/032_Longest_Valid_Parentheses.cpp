#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <stack>

using namespace std;

// stack version
class Solution {
public:
	class pairs{
	public:
		int loc;
		char signal;
		pairs(int a, char b) {
			loc = a; signal = b;
		}
	};
	int longestValidParentheses(string s) {
		stack<pairs> stk;
		int maxLen = 0, iStart = 0;
		for (int i = 0; i < s.size(); i++) {
			pairs tmp(i, s[i]);
			if (s[i] == '(')
				stk.push(tmp);
			else {
				if (stk.empty() || stk.top().signal == ')') {
					pairs tmp(i, s[i]);
					stk.push(tmp);
				}
				else { // if top == '('
					stk.pop();
					if (stk.empty())
						maxLen = i + 1; // stk.top() has mistake when stk is empty
					else
						maxLen = max(maxLen, i - stk.top().loc);// when stk is not empty, update the starting point
				}

			}
		}
		return maxLen;
	}
};


//
class Solution2 {
public:
	// x   x   x   (   x   x   )
	// . . . . j   j+1     i-1 i 
	int longestValidParentheses(string s) {
		int maxLen = 0, n = s.size();
		if (n < 2)
			return 0;
		int dp[n] = {0}; // dp[i]: length of longest substring ended at i, 
		for (int i = 1; i < n; i++) {
			int j = i - dp[i - 1] - 2;
			if (j < -1 or s[j + 1] == ')' or s[i] == '(') { // j = -1 represents j not in such ()(())
				dp[i] = 0;
			}
			else {
				dp[i] = dp[j] + 2 + dp[i - 1];
				maxLen = max(maxLen, dp[i]);
			}
		}
		return maxLen;
	}
};

int main() {
	Solution2 s;
	cout << s.longestValidParentheses("()(())") << endl;
}
