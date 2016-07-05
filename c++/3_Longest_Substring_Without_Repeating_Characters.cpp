class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last = -1;
        int maximum = 0;
        int n = s.size();
        map<char, int> dict;
        for (int i = 0; i < n; i++) {
            if ((dict.count(s[i]) != 0) && (last < dict[s[i]])) {
                last = dict[s[i]];
            }
            dict[s[i]] = i;
            maximum = max(i - last, maximum);
        }
        
        return maximum;
        
    }
};