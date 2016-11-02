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
    int singleNumber(vector<int> A) {
        int res = 0;
        int n = A.size();
        for(int i=31; i>=0; i--) {
            int sum = 0;
            int mask = 1<<i;
            for(int j=0; j<n; j++) {
                if(A[j] & mask)  // 1 & 0 = 0
                    sum++;
            }
            res = (res<<1) + (sum%3);
        }
        return res;
    }
};


int main() {
	Solution s;
    Examples eg;
    vector<int> A;
    A.push_back(1);
    A.push_back(3);
    A.push_back(3);
    A.push_back(3);


    cout << s.singleNumber(A);
}
