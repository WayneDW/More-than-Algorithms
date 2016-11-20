#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> letterCombinations(string digits) {
    	vector<string> res;
    	if (digits == "")
    		return res;
    	res.push_back("");
    
        string Lists[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        for (int i = 0; i < digits.size(); i++) {
        	vector<string> tmp;
        	for (int j = 0; j < res.size(); j++){
        		string tmpStr = Lists[digits[i] - '0'];
        		for (int k = 0; k < tmpStr.size(); k++) {
        			tmp.push_back(res[j] + tmpStr[k]);
        		}
        	}
        	res = tmp;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<string> str;
    str = s.letterCombinations("23");
    for (int i = 0; i < str.size(); i++)
    	cout << str[i] << endl;
    
}
