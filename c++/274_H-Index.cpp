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
        sort(citations.begin(), citations.end());
        
        //print1dVector(citations);
        for (int i = 0; i < citations.size(); i++) {
            //cout << citations[i] << " " << len << endl;
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
    int dat[] = {2,0,6,1,5};
    vector<int> citations(dat, dat+sizeof(dat)/sizeof(int));
    cout << s.hIndex(citations) << endl;


}
