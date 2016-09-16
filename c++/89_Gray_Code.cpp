#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
    	vector<int> res;
    	if (n < 0)
    		return res;
    	res.push_back(0);
    	int shift = 1;
    	for (int i = 0; i < n; i++) {
    		for (int j = res.size() - 1; j >= 0; j--)
    			res.push_back(res[j] + shift);
    		shift <<= 1;
    	}
    	return res;
    }
};