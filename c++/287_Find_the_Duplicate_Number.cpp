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

class Solution_fake { // it uses values rather than reference of nums, it consumes additional memory
public:
    int findDuplicate2(vector<int> nums) {
        sort(nums.begin(), nums.end());
        if (nums.size() == 0) return 0;
        int last = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (last == nums[i])
                return nums[i];
            last = nums[i];
        }
        return 0;
    }
};


// a much better idea is to use two pointers, fast and slow
// think of the array as a linked list based on its own index
// [3,1,2,5,3,4]  3->5->4->3->5->3
// which can regarded as 
// 3->5->4->3
//    |-----|   
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() == 0) return -1;
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};


int main() {
	Solution s;
    Examples eg;
    int dat[] = {1,3,4,2,2};
    vector<int> vec(dat, dat+5);
    cout << s.findDuplicate(vec);
}
