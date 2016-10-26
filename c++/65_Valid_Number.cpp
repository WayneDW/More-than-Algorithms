#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool isNumber(string s) {
        string numList = "0123456789.e";
        int l = 0, r = 0, n = s.size();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                l = i;
                break;
            }
        }
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') {
                r = i;
                break;
            }
        }
        s = s.substr(l, r - l + 1);
        if (s.size() == 0)
            return false;
        if (s[0] == '+' or s[0] == '-') s = s.substr(1);
        if (s == "." or s[0] == 'e' or s[s.size() - 1] == 'e')
            return false;
        if (s.substr(0, 2) == ".e") return false;
        if (s.size() >= 2) {
            string tmp = s.substr(s.size() - 2, 2);
            if (tmp == "e." or tmp == "e+" or tmp == "e-")
                return false;
        }
        int tag = 0, tage = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') tag++;
            else if (s[i] == 'e') tage++;
            else if (i > 0 and (s[i] == '+' or s[i] == '-') and s[i - 1] == 'e')
                continue;
            int loc = numList.find(s[i]);
            if (loc < 0)
            return false;
        }
        if (tag > 1 or tage > 1) return false;
        int loc1 = s.find('e');
        if (loc1 >= 0) {
            string sr = s.substr(loc1 + 1);
            for (int i = 0; i < sr.size(); i++) {
                if (sr[i] == '.')
                    return false;
            }
        }
        return true;
    }
};


int main() {
	Solution s;
    cout << s.isNumber(" 005047e+6") << endl;
}