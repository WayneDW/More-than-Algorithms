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

/*For a undirected graph with tree characteristics, we can choose any node as the root. The result graph
is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height
 trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected 
edges (each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] 
and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]*/

/*Hint:

How many MHTs can a graph have at most?*/



class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        // initialize graph
        vector<unordered_set<int> > graph(n);
        for (auto pr: edges) {
            graph[pr.first].insert(pr.second);
            graph[pr.second].insert(pr.first);
        }
        // take care of corner case
        vector<int> leafSet;
        if (n == 1) {
            leafSet.push_back(0);
            return leafSet;
        }

        // get the leaf nodes of the initial graph
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1) leafSet.push_back(i);
        }
        // iterately delete leaf nodes, note: it is essentially BFS
        while (1) {
            vector<int> inner_LeafSet;
            for (int i : leafSet) {
                for (int neigh : graph[i]) {
                    graph[neigh].erase(i);
                    if (graph[neigh].size() == 1) inner_LeafSet.push_back(neigh);
                }
            }
            if (inner_LeafSet.empty()) return leafSet;
            leafSet = inner_LeafSet;
        }
    }
};

int main() {
    Solution s;
    Examples eg;
}
