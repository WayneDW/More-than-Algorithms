#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
    	int m = a.size();
    	int n = b.size();
    	if (m < n)
    		return addBinary(b, a);
    	int total, carry = 0;
    	string res;
    	for (int i = 0; i < m; i++) {
    		total = a[m - 1 - i] - '0' + carry;
    		if (i < n)
    			total += b[n - 1 - i] - '0';
    		cout << total << endl;
    		carry = total / 2;
    		res.push_back(total % 2 + '0');
    	}
    	if (carry)
    		res.push_back('1');
    	reverse(res.begin(), res.end());
    	return res;
    }
};


int main() {
	Solution s;
	cout << s.addBinary("11", "1") << endl;


}
