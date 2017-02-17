#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
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

/*Given a list of airline tickets represented by pairs of departure and arrival airports 
[from, to], reconstruct the itinerary in order. All of the tickets belong to a man who 
departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the 
smallest lexical order when read as a single string. For example, the itinerary 
["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.*/

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> itinerary;
        if (!tickets.size()) return itinerary;
        unordered_map<string, multiset<string>> mp;
        for (auto i: tickets) mp[i.first].insert(i.second);
        stack<string> stk;
        stk.push("JFK");
        while (!stk.empty()) {
            string cur = stk.top();
            if (!mp[cur].empty()) {
                stk.push(*mp[cur].begin()); // automatically choose smaller lexical order
                mp[cur].erase(mp[cur].begin()); // delete visited path
            }
            else {
                itinerary.push_back(cur);
                stk.pop();
            }
        }
        reverse(itinerary.begin(), itinerary.end());
        return itinerary;
    }
};


int main() {
    Solution s;
    Examples eg;
    vector<pair<string, string>> tickets;
    tickets.push_back(make_pair("JFK","SFO"));
    tickets.push_back(make_pair("JFK","ATL"));
    tickets.push_back(make_pair("SFO","ATL"));
    tickets.push_back(make_pair("ATL","JFK"));
    tickets.push_back(make_pair("ATL","SFO"));
    print(s.findItinerary(tickets));
}

