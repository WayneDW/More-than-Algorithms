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

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};


// {0,1,2#1,2#2,2}.
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        UndirectedGraphNode *copy = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode*> q;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> ht;
        ht[node] = copy;
        q.push(node); // use BFS to visit all the nodes, then copy while visiting
        while (!q.empty()) {
            UndirectedGraphNode* node = q.front(); q.pop();
            copy = ht[node];
            vector<UndirectedGraphNode*> neigh = node->neighbors;
            for (int i = 0; i < neigh.size(); i++) {
                if (ht.count(neigh[i]) == 0) {
                    UndirectedGraphNode* tmp = new UndirectedGraphNode(neigh[i]->label);
                    ht[neigh[i]] = tmp;
                    copy->neighbors.push_back(tmp);
                    q.push(neigh[i]);
                }
                else copy->neighbors.push_back(ht[neigh[i]]); // essential part, to avoid endless loop
            }
        }
        return ht[node];
    }
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return NULL;
        if (mp.count(node) == 0) {
            mp[node] = new UndirectedGraphNode(node->label);
            for (auto neigh: node->neighbors)
                mp[node]->neighbors.push_back(cloneGraph(neigh));
        }
        return mp[node];
    } 
private:
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> mp;
};

int main() {
    Solution s;
    Examples eg;
    UndirectedGraphNode* g1 = new UndirectedGraphNode(1);
    UndirectedGraphNode* g2 = new UndirectedGraphNode(2);
    UndirectedGraphNode* g3 = new UndirectedGraphNode(3);
    vector<UndirectedGraphNode *> v1, v2, v3;
    v1.push_back(g2);
    v1.push_back(g3);
    v2.push_back(g3);
    v3.push_back(g3);
    g1->neighbors = v1;
    g2->neighbors = v2;
    g3->neighbors = v3;
    UndirectedGraphNode* res = s.cloneGraph(g1);
}
