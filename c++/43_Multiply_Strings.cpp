#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
    	reverse(num1.begin(), num1.end());
    	reverse(num2.begin(), num2.end());
    	int m = num1.size(), n = num2.size();
    	int digit, carry, arr[m + n] = {0};
    	for (int i = 0; i < m; i++)
    		for (int j = 0; j < n; j++)
    			arr[i + j] += (num1[i] - '0') * (num2[j] - '0');

    	string ans = "";
    	for (int i = 0; i < m + n; i++) {
    		digit = arr[i] % 10;
    		carry = arr[i] / 10;
    		if (i != m + n - 1)
    			arr[i + 1] += carry;
    		ans = to_string(digit) + ans;
    	}

    	while (ans[0] == '0' && ans.size() > 1)
    		ans.erase(ans.begin());
    	return ans;
    }
};


int main() {
	Solution s;
	string num1, num2;
	num1 = "123", num2= "987";
	cout << s.multiply(num1, num2) << endl;



}
