#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include "func.cpp"

using namespace std;


class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        if (!len) return 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= len)
                break;
            len--;
        }
        return len;   
    }
};

int main() {
	Solution s;
    Examples eg;
}
