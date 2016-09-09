#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
    	int n = s.size();
    	int tag = 1;
    	int cnt = 0;
    	for (int i = n - 1; i > -1; i--) {
    		if (s[i] == ' ' and tag)
    			continue;
    		else if (s[i] != ' ' && tag)
    			tag = 0;
    		if (s[i] == ' ' && !tag)
    			break;
    		cnt++;
    	}
        return cnt;
    }
};


int main() {
	Solution s;
	cout << s.lengthOfLastWord("asd dsadasd sd ") << endl;
}
