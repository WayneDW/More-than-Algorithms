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

/*Given a string of numbers and operators, return all possible results from computing all 
the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]*/

class Solution_slow_clear_version {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i = 0; i < input.size(); i++) {
            char c = input[i];
            if (c == '+' || c == '-' || c == '*') {
                vector<int> res1 = diffWaysToCompute(input.substr(0, i)); // take care, this is i, rather than i - 1
                vector<int> res2 = diffWaysToCompute(input.substr(i + 1));
                // put values in res
                for (int num1 : res1) {
                    for (int num2 : res2) {
                        if (c == '+') res.push_back(num1 + num2);
                        else if (c == '-') res.push_back(num1 - num2);
                        else res.push_back(num1 * num2);
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(input)); // if it only contain numbers
        return res;
    }
};

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        map<pair<int, int>, vector<int> > dt; // bug in unordered_map, or you can use key of string
        return dfs(input, 0, input.size() - 1, dt);
    }
private:
    vector<int> dfs(string& input, int start, int end, map<pair<int, int>, vector<int> >  &dt) {
        pair<int, int> pr(start, end);
        if (dt.count(pr)) return dt[pr];
        int num = 0;
        vector<int> res;
        for (int i = start; i <= end; i++) {
            char c = input[i];
            if (c != '+' && c != '-' && c != '*') num = 10 * num + c - '0';
            else {
                vector<int> l = dfs(input, start, i - 1, dt);
                vector<int> r = dfs(input, i + 1, end, dt);
                for (auto num1 : l) {
                    for (auto num2 : r) {
                        if (c == '+') res.push_back(num1 + num2);
                        else if (c == '-') res.push_back(num1 - num2);
                        else res.push_back(num1 * num2);
                    }
                }
            }
        }
        if (res.empty()) res.push_back(num);
        return dt[pr] = res; // return res and do dt[pr] = res;
    }
};

int main() {
    Solution s;
    Examples eg;
    cout << s.diffWaysToCompute("2-1-1") << endl;
}
