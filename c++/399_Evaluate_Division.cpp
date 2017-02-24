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

/*Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a 
real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where 
equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.*/

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        for (int i = 0; i < equations.size(); i++) {
            auto pr = equations[i];
            graph[pr.first].insert(pr.second);
            graph[pr.second].insert(pr.first);
            coef[pr.first + ' ' + pr.second] = values[i];
            coef[pr.second + ' ' + pr.first] = 1 / values[i];
        }
        vector<double> res(queries.size(), 0);
        unordered_set<string> visited;
        // cout << coef["d b"] << endl; // it equals 0 by default with non-existing key
        for (int i = 0; i < queries.size(); i++) {
            double tmp = DFS(queries[i].first, queries[i].second, visited, 1);
            res[i] = tmp == 0? -1: tmp; // good trick here 
        }
        return res;
    }

    double DFS(string a, string b, unordered_set<string> &visited, double val) { // using reference speeds up greatly
        if (graph.find(a) == graph.end()) return 0;
        if (visited.find(a) != visited.end()) return 0;
        if (coef.find(a + ' ' + b) != coef.end()) return val * coef[a + ' ' + b];
        double tmp = 0;
        visited.insert(a);
        for (auto neigh: graph[a]) {
            tmp = DFS(neigh, b, visited, val * coef[a + ' ' + neigh]);
            if (tmp != 0) break;
        }
        visited.erase(a);
        return tmp;
    }
private:
    unordered_map<string, unordered_set<string>> graph;
    unordered_map<string, double> coef;    
};


int main() {
    Solution s;
    Examples eg;
    vector<pair<string, string>> equations = {make_pair("a", "b"), make_pair("b", "c")};
    vector<double> values = {2, 3};
    vector<pair<string, string>> queries = {make_pair("a", "c")};
    print(s.calcEquation(equations, values, queries));
}
