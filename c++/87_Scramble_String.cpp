#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;
        if (s1.size() != s2.size())
            return false;
        int len = s1.length();
        // slower version            
        // string ss1 = s1;
        // sort(ss1.begin(), ss1.end());
        // string ss2 = s2;
        // sort(ss2.begin(), ss2.end());
        // if (ss1 != ss2)
        //     return false;
        
        int cnt[26] = {0};
        for (int i = 0; i < s1.size(); i++){
            cnt[s1[i] - 'a']++;
            cnt[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (cnt[i] != 0)
                return false;
        }

        
        for (int i = 1; i < s1.size(); i++)
        {
            if (isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if (isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
                return true;
        }
        return false;
    }
};

int main() {
	Solution s;
    cout << s.isScramble("a", "b") << endl;
}