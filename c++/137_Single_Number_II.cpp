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

/*Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?*/


/*idea is that we iterate every bit for an integer, this means we need to check 32 bits 
For every bit, since only one digit appears once and others appear 3 times, this means we can get that number by using %3*/

class Solution {
public:
    int singleNumber(vector<int> A) {
        int res = 0;
        for(int i = 31; i >= 0; i--) {
            int sum = 0;
            int mask = 1 << i;
            for(int j = 0; j < A.size(); j++) {
                if(A[j] & mask)  // 1 & 0 = 0
                    sum++;
            }
            res = (res << 1) + (sum % 3);
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
