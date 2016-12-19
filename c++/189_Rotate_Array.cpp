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
    void rotate(vector<int>& nums, int k) {
        if (k <= 0) return;
        while (k-- > 0) {
            int tmp = nums.back();
            nums.erase(nums.end() - 1);
            nums.insert(nums.begin(), tmp);
        }

    }
};

int main() {
    Solution s;
    Examples eg;
    int tmp[] = {1,2,3,4,5,6,7};
    vector<int> vec(tmp, tmp + 7);
    s.rotate(vec, 3);
    print1dVector(vec);
}
