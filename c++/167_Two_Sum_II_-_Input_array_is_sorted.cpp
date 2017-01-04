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


/*
Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left = 0, right = numbers.size() - 1;
        while (1) {
            if (numbers[left] + numbers[right] > target) right--;
            else if (numbers[left] + numbers[right] < target) left++;
            if (numbers[left] + numbers[right] == target) break;
        }
        res.push_back(left + 1);
        res.push_back(right + 1);
        return res;
    }
};

int main() {
    Solution s;
    Examples eg;
}
