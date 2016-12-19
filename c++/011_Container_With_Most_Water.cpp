#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <string>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int water, out = 0;
        int left = 0;
        int right = height.size() - 1;
        while (left < right) {
            water = min(height[left], height[right]) * (right - left);
            // cout << water << " " << left << " " << right << endl;
            if (out < water) out = water;
            if (height[left] < height[right]) left += 1;
            else right -= 1;
        }
        return out;
    }


};

int main() {
    Solution s;
    vector<int> height;
    height.push_back(1);
    height.push_back(2);
    height.push_back(0);
    height.push_back(3);

    cout << s.maxArea(height) << endl;
}
