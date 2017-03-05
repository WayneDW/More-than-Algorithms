#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

/*A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly 
alternate between positive and negative. The first difference (if one exists) may be either positive or 
negative. A sequence with fewer than two elements is trivially a wiggle sequence.

For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive
 and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first 
 two differences are positive and the second because its last difference is zero.

Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence 
is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the 
remaining elements in their original order.

Examples:
Input: [1,7,4,9,2,5]
Output: 6
The entire sequence is a wiggle sequence.

Input: [1,17,5,10,13,15,10,5,16,8]
Output: 7
There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].

Input: [1,2,3,4,5,6,7,8,9]
Output: 2
Follow up:
Can you do it in O(n) time?*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        int dp_pos[n] = {1}, dp_neg[n] = {1};
        bool tag_pos = true, tag_neg = true;
        for (int i = 1; i < n; i++) {
            dp_pos[i] = dp_pos[i-1];
            dp_neg[i] = dp_neg[i-1];
            if (nums[i] == nums[i-1]) continue;
            if ((tag_pos && nums[i] > nums[i-1]) || (!tag_pos && nums[i] < nums[i-1])){
                dp_pos[i]++;
                tag_pos = !tag_pos;
            }
            if ((tag_neg && nums[i] < nums[i-1]) || (!tag_neg && nums[i] > nums[i-1])) {
                dp_neg[i]++;
                tag_neg = !tag_neg;
            }

        }
        return max(dp_pos[n-1], dp_neg[n-1]);
    }
};

int main() {
    Solution s;
    Examples eg;
    vector<int> nums = {0, 0};
    cout << s.wiggleMaxLength(nums) << endl;
}
