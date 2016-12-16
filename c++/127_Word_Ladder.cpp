#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

/*Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.*/


/*
1, insert endword to wordlist
2, BFS search, change 25 nodes, every level, length+=1
3, to avoid visiting multiply times, erase the dictionary*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        int length = 1;
        queue<string> q;
        q.push(beginWord);
        while (!q.empty()) {
            int size = q.size();
            length++;
            for (int i = 0; i < size; i++) {
                string tmp = q.front(); q.pop();
                for (int j = 0; j < tmp.size(); j++) {
                    char backup = tmp[j];
                    for (int k = 0; k < 26; k++) {
                        if (tmp[j] - 'a' == k) continue;
                        tmp[j] = 'a' + k;
                        if (tmp == endWord) return length;
                        if (wordList.count(tmp) > 0) {
                            q.push(tmp);
                            // to avoid visiting a word for more than once, we erase it from dict once it is visited.
                            wordList.erase(tmp); 
                        }
                        tmp[j] = backup;
                    }
                }
            }
        }
        return 0;
    }
};

int main() {
	Solution s;
    Examples eg;
    unordered_set<string> wordList;
    wordList.insert("hot");
    wordList.insert("dot");
    wordList.insert("dog");
    wordList.insert("lot");
    wordList.insert("log");
    cout << s.ladderLength("hit", "cog", wordList) << endl;

}
