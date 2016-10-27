#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        vector<string> stk;
        string line = "";
        if (maxWidth == 0){
            res.push_back(line);
            return res;
        }
        int totalLen = 0;
        for (int i = 0; i < words.size(); i++) {
            int wlen = words[i].size();
            if (i > 0 and totalLen + wlen + stk.size() > maxWidth){
                if (stk.size() > 1) {
                    int lenSpaces = maxWidth - totalLen;
                    if (stk.size() > 2) {
                        int lenavg = lenSpaces / (stk.size() - 1);
                        int lenArr[stk.size() - 1] = {0};
                        int firstNum = lenSpaces - lenavg * (stk.size() - 1);
                        string tmp(lenavg, ' ');
                        for (int j = 0; j < firstNum; j++)
                            line += stk[j] + tmp + ' ';
                        for (int j = firstNum; j < stk.size() - 1; j++)
                            line += stk[j] + tmp;
                        line += stk.back();
                    }
                    else {
                        string tmp(lenSpaces, ' ');
                        line = stk[0] + tmp + stk[1];
                    }
                }
                else{
                    string tmp((maxWidth - stk[0].size()), ' ');
                    line = stk[0] + tmp;
                }
                res.push_back(line);
                line = "";
                totalLen = 0;
                stk.clear();
            }
            totalLen += wlen;
            stk.push_back(words[i]);
        }
        if (stk.size() == 1) {
            string tmp((maxWidth - stk[0].size()), ' ');
            line = stk[0] + tmp;
        }
        else{
            for(int i = 0; i < stk.size(); i++)
                line += stk[i] + " ";
            string tmp((maxWidth - line.size()), ' ');
            line += tmp;
        }
        res.push_back(line);
        return res;
    }
};


int main() {
	Solution s;
    // ["What","must","be","shall","be."]
    string a1 = "what";
    string a2 = "must";
    string a3 = "be";
    string a4 = "shall";
    string a5 = "be.";
    vector<string> words;
    words.push_back(a1);
    words.push_back(a2);
    words.push_back(a3);
    words.push_back(a4);
    words.push_back(a5);
    vector<string> res = s.fullJustify(words, 12);

    cout << res[0] << endl;

}