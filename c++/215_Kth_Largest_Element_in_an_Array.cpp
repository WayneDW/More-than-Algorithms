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
#include "000_basic.cpp"

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

class Solution3 { 
public:
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l <= r) {
            if (nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot) l++; 
            if (nums[r] <= pivot) r--;
        }
        swap(nums[left], nums[r]);
        return r;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k - 1) return nums[pos];
            if (pos > k - 1) right = pos - 1;
            else left = pos + 1;
        }
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // build a heap
        int heapSize = nums.size();
        for (int i = (heapSize >> 1) - 1; i >= 0; i--) {
            heapify(nums, i, heapSize);
        }
        // pop the top k-1 items
        for (int i = 0; i < k - 1; i++)
            heapPop(nums, heapSize);
        // pop the target
        return nums[0];
    }

    void heapify(vector<int>& nums, int node, int heapSize) {
        int left = (node << 1) + 1;
        int right = (node << 1) + 2;
        int pivot = node;
        if (left < heapSize && nums[left] > nums[node]) node = left;
        if (right < heapSize && nums[right] > nums[node]) node = right;
        if (pivot != node) {
            swap(nums[node], nums[pivot]);
            // make sure the middle part modify the lower part, and the lower part still maintain heap structure
            heapify(nums, node, heapSize);
        }
    }

    void heapPop(vector<int>& nums, int& heapSize) {
        swap(nums[0], nums[heapSize-1]);
        heapSize--;
        heapify(nums, 0, heapSize);
    }
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
	Solution3 s;
    Examples eg;
    int dat[6] = {3,2,1,5,6,4};
    //int dat[7] = {7,6,5,4,3,2,1};
    //int dat[27] = {3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    cout << sizeof(dat) /sizeof(int) << endl;
    vector<int> nums(dat, dat + sizeof(dat) / sizeof(int));
    cout << s.findKthLargest(nums, 2) << endl;
}
