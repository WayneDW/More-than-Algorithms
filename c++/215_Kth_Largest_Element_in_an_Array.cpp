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

// heap tutorial www.tutorialspoint.com/data_structures_algorithms/heap_data_structure.htm            
// this line still holds when we build the max heap
//     5              5            20           20
//    /   node 10    /   node 5    /   node 5   /
//   10   ------>   20  ------->  5 ---------> 10
//   /             /             /            /
//  20            10            10           5


// a very good tutorial about quick sort (divide conquer, master method) and heap sort
// discuss.leetcode.com/topic/15256/4-c-solutions-using-partition-max-heap-priority_queue-and-multiset-respectively
// the quick sort idea is this
// do partition for nums[0], using o(n) time, smaller point is set before pivot, bigger...
// if k is in the right position, return
// if item is in the right, divide the problem in the right part
// otherwise divide the problem in the left part
// T(n) = T(n/2) + o(n)


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // heapify
        heapSize = nums.size();
        for (int i = (heapSize >> 1) - 1; i >= 0; i--)
            heapify(nums, i);
        // pop k-1 times
        for (int i = 0; i < k - 1; i++)
            heapPop(nums);
        return nums[0];
        // return the top
    }
    void heapify(vector<int>& nums, int idx) {
        int pivot = idx;
        int left = (idx << 1) + 1;
        int right = (idx << 1) + 2;
        if (left < heapSize && nums[pivot] < nums[left]) pivot = left; 
        if (right < heapSize && nums[pivot] < nums[right]) pivot = right; 
        if (idx != pivot) {
            swap(nums[idx], nums[pivot]);
            heapify(nums, pivot);
        }
    }
    void heapPop(vector<int>& nums) {
        swap(nums[0], nums[heapSize-1]);
        heapSize--;
        heapify(nums, 0);
    }
private:
    int heapSize;
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q(nums.begin(), nums.end());
        for (int i = 0; i < k - 1; i++)
            q.pop();
        return q.top();
    }
}; 


int main() {
	Solution s;
    Examples eg;
    int dat[6] = {3,2,1,5,6,4};
    //int dat[7] = {7,6,5,4,3,2,1};
    //int dat[27] = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    cout << sizeof(dat) /sizeof(int) << endl;
    vector<int> nums(dat, dat + sizeof(dat) / sizeof(int));
    cout << s.findKthLargest(nums, 2) << endl;
}
