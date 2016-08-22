#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

/*
For example, given:
"barfoothefoobarman"  ["foo", "bar"] return the indices: [0,9].
"barfoo-foo bar the-foobarman"  ["bar","foo","the"]   [6,9,12]
"wordgoodgoodgoodbestword", ["word","good","best","good"] [8]
*/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    	int strLen = s.size();
    	int wordLen = words[0].size();
    	int wordNum = words.size();

    	vector<int> res;
    	map<string, int> dict;
    	for (int i = 0; i < wordNum; i++)
    		dict[words[i]]++;
    	/*
    	map<string, int>::iterator it;
    	for (it = dict.begin(); it != dict.end(); it++) {
    		cout << it->second << endl;
    	}*/

    	if (strLen < wordNum * wordLen)
    		return res;
    	for (int i = 0; i < strLen - wordNum * wordLen + 1; i++) {
    		string subStr = s.substr(i, wordNum * wordLen);
    		if (match(i, wordNum, wordLen, subStr, dict, words))
    			res.push_back(i);
    	}

    	return res;
        
    }
    bool match(int start, int wordNum, int wordLen, string subString, map<string, int> &dict, vector<string> &words) {
    	map<string, int> cnt;
    	for (int i = 0; i < wordNum; i++) {   		
    		string subSubStr = subString.substr(i * wordLen, wordLen);
    		if (dict.count(subSubStr) > 0) {
    			cnt[subSubStr]++;
    			if (start == 0)
    				cout << subSubStr << " " << cnt[subSubStr] << " " <<  dict[subSubStr] << endl;
    		}
    		else
    			return 0;
    		if (cnt[subSubStr] > dict[subSubStr])
    			return 0;
    	}
    	return 1;
    }
};




int main() {
	Solution ans;
	string s = "barfoofoobarthefoobarman";
	vector<string> words;
	words.push_back("foo");
	words.push_back("bar");
	words.push_back("the");
	vector<int> res = ans.findSubstring(s, words);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;



}
