



class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        std::unordered_set <char> dict1 = { 'q','Q','w','W','e','E','r','R','t','T','y','Y','u','U','i','I','o','O','p','P' };
        std::unordered_set <char> dict2 = { 'a','A','s','S','d','D','f','F','g','G','h','H','j','J','k','K','l','L'};
        std::unordered_set <char> dict3 = { 'z','Z','x','X','c','C','v','V','b','B','n','N','m','M'};

        vector<string> res;

        for (auto &word : words) {
            bool d1 = true, d2 = true, d3 = true;
            for (auto & ch : word) {
                if (d1) {
                    if (dict1.count(ch) == 0) d1 = false;
                }

                if (d2) {
                    if (dict2.count(ch) == 0) d2 = false;
                }

                if (d3) {
                    if (dict3.count(ch) == 0) d3 = false;
                }
            }

            if (d1 || d2 || d3) res.push_back(word);
        }

        return res;
    }
};