#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
	void tmp(vector<string> a) {
		cout << a[0] << endl;
		cout << a[1] << endl;
	}
};


int main() {
    Solution s;
    vector<string> ss;
    string d, dd;
    d = "(";
    dd = ")";
    ss.push_back(d);
    ss.push_back(dd);
    s.tmp(ss);
    
}
