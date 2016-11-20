#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 2; i < n + 1; i++)
            s = count(s);
        return s;
    }

    string count(string s) {
    	
    	int count = 0;
    	int n = s.size();

    	char last = '.';
    	string res = "";
    	
    	for (int i = 0; i < n; i++) {
    		if (last != '.' && last != s[i]) {
    			res += to_string(count) + last;
    			count = 0;
    		}
    		count++;
    		last = s[i];
    	}
    	
		res += to_string(count) + last;
    	
    	return res;
    }
};

int main() {

	Solution s;
	cout << s.countAndSay(1) << endl;

}
