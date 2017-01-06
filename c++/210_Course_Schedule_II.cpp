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

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<unordered_set<int> > graph(numCourses);
        for (auto pr: prerequisites) graph[pr.second].insert(pr.first); // create the graph
        vector<int> res;
        vector<pair<bool, bool> > visited(numCourses, pair<bool, bool>(false, false));
        stack<int> stk;
        bool cycle = false;
        for (int i = 0; i < graph.size(); i++) {
            if (visited[i].second == false) { // second means the node has been visited
                DFS(i, graph, visited, stk, cycle);
                if (cycle) return res;
            }
        }
        while (!stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        return res;
    }

    void DFS(int i, vector<unordered_set<int> > &graph, vector<pair<bool, bool> > &visited, stack<int> &stk, bool &cycle) {
        if (visited[i].first == true && visited[i].second == false) {cycle = true; return;}

        visited[i].first = true; // we are now in a DFS loop
        for (auto neigh: graph[i]) {
            if (visited[neigh].second == false) // second means the node has been visited
                DFS(neigh, graph, visited, stk, cycle);
            if (cycle) return;
        }
        visited[i].first = false; // the DFS loop stops
        visited[i].second = true;
        stk.push(i);
    }
};


int main() {
    Solution s;
    Examples eg;
    vector<pair<int, int> > prerequisites = {pair<int, int>(0, 1)};
    printVector(s.findOrder(2, prerequisites));
}
