#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;


/*Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.*/


/*Due to duplicates, we can't throw away the right half when 

              l    mid       r
    case  1   3    3    3    1

              l         mid            r
    case  2:  3    3    3    1    2    3    take care of nums[mid] == nums[right]


              3    0    1    1    1

              l             mid             r
    case  3:  3    3    3    1    2    3    3   this can't derive left = mid due to case 4

              l         mid       r
    case  4:  3    0    1    1    3

*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[left] < nums[right]) break; // this is clear
            if (nums[mid] > nums[right]) left = mid + 1; // we can have left = mid + 1, since 
            else if (nums[mid] == nums[right]) { // case 2
                left++; right--;
            }
            else right = mid; // see case 3, we can't have right = mid - 1
        }
        return nums[left];
    }
};


int main() {
    Solution s;
    Examples eg;
}
