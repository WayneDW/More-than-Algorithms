#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include "func.cpp"

using namespace std;


class Solution {
public:
    string reverseString(string s) {
        for (int i = 0; i < s.size() / 2; i++) {
            char tmp = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size() - i - 1] = tmp;
        }
        return s;
    }
};

int main() {
	Solution s;
    Examples eg;
}
