#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
    	int factorial = 1;
    	for (int i = 1; i < n; i++)
    		factorial *= i;
    	k--;
    	int sets[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    	vector<int> setNum(sets, sets + 9);
    	string res;
    	int tag = 0;
    	while (k >= 0 && tag < n) {
    		tag++;
    		int quotient = k / factorial;
    		k -= quotient * factorial;
    		res.push_back('0' + setNum[quotient]);
    		setNum.erase(setNum.begin() + quotient);
    		if (n == tag)
    			factorial = 1;
    		else
    			factorial /= (n - tag);
    	}
    	return res;
    }
};

int main() {
	Solution s;
	cout << s.getPermutation(2, 1) << endl;

}