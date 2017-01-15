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

/*Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.*/


struct SegmentTree {
    int start, end, sum;
    SegmentTree *left, *right;
    SegmentTree(int a, int b): start(a), end(b), sum(0), left(nullptr), right(nullptr) {}
};

class NumArray {
private:
    
    SegmentTree* root;

    SegmentTree* buildTree(vector<int> &nums, int start, int end) { // this case return int is not a good choice
        if (start > end || start < 0 || end >= nums.size()) return nullptr;
        SegmentTree* root = new SegmentTree(start, end);
        if (start == end) {
            root->sum = nums[start];
            return root;
        }

        int mid = start + (end - start) / 2;
        root->left = buildTree(nums, start, mid);
        root->right = buildTree(nums, mid + 1, end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }

    int updateTree(int pos, int val, int start, int end, SegmentTree* root) {
        int diff;
        if (root && pos == start && pos == end) {
            diff = val - root->sum;
            root->sum = val;
            return diff;
        }

        int mid = start + (end - start) / 2;
        if (pos <= mid) diff = updateTree(pos, val, start, mid, root->left);
        else diff = updateTree(pos, val, mid + 1, end, root->right);
        root->sum += diff;
        return diff;
    }

    int findSum(int i, int j, SegmentTree* root) {
        if (!root) return 0;
        if (root && i == root->start && j == root->end) return root->sum;
        int mid = root->start + (root->end - root->start) / 2;
        if (j <= mid) return findSum(i, j, root->left);
        else if (i > mid) return findSum(i, j, root->right);
        return findSum(i, mid, root->left) + findSum(mid + 1, j, root->right);
    }

    
    int arraySize;


public:
    NumArray(vector<int> &nums) {
        arraySize = nums.size();
        root = buildTree(nums, 0, nums.size() - 1);
    }

    void update(int i, int val) {
        updateTree(i, val, 0, arraySize - 1, root);
    }

    int sumRange(int i, int j) {
        return findSum(i, j, root);
    }
};


// Your NumArray object will be instantiated and called as such:


int main() {
    Examples eg;
    vector<int> nums = {1, 3, 5};
    NumArray numArray(nums);
    cout << numArray.sumRange(0, 2) << endl;
    numArray.update(1, 2);
    cout << numArray.sumRange(0, 2) << endl; 
}
