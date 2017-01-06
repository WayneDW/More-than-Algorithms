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

/*There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have 
to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it 
possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, 
and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. 
Read more about how a graph is represented.

click to show more hints.

Hints:
1. This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, 
    no topological ordering exists and therefore it will be impossible to take all courses.
2. Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic 
    concepts of Topological Sort.
3. Topological sort could also be done via BFS.*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<unordered_set<int> > graph(numCourses);
        for (auto pr: prerequisites) graph[pr.second].insert(pr.first);

        bool cycle = false;
        for (int i = 0; i < graph.size(); i++) {
            if (visited[i] == 0) {
                DFS(i, visited, graph, cycle);
                if (cycle) return false;
            }
        }
        return true;
    }
    // without & before graph, time limit exceeded
    void DFS(int classNo, vector<int> &visited, vector<unordered_set<int> > &graph, bool &cycle) {
        if (visited[classNo] == 1) { cycle = true; return; }
        visited[classNo] = 1;
        for (auto neigh: graph[classNo]) {
            DFS(neigh, visited, graph, cycle);
            if (cycle) return;
        }
        visited[classNo] = 2;
    }
};


/* BFS: start with a node with in-degree 0, if not return false; set the node as -1 to 
avoid visiting again and reduce its neighbor values by 1 and repeat...*/


int main() {
    Solution s;
    Examples eg;
    vector<pair<int, int> > prerequisites = {pair<int, int>(0, 1)};
    cout << s.canFinish(2, prerequisites) << endl;

}
