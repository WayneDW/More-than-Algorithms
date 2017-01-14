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

/*Given a 2D board and a list of words from the dictionary, find all words in the board.

Each word must be constructed from letters of sequentially adjacent cell, where "adjacent" 
cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

For example,
Given words = ["oath","pea","eat","rain"] and board =

[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
Note:
You may assume that all inputs are consist of lowercase letters a-z.

click to show hint.

You would need to optimize your backtracking to pass the larger test. Could you stop backtracking earlier?

If the current candidate does not exist in all words' prefix, you could stop backtracking immediately. 
What kind of data structure could answer such query efficiently? Does a hash table work? Why or why not? 
How about a Trie? If you would like to learn how to implement a basic trie, please work on this problem: 
Implement Trie (Prefix Tree) first.*/


/* We can't use hash because that will cost too much memory to save happy, h, ha, hap, happ...
Regardding larger test set: use prefix tree
The basic algorithm is DFS, however we need to avoid repeating, therefore a trace is used.
But the problem with trace is the low speed, thus we can change the matrix value and convert it back*/

class Solution { // avoid repeating, unknown bug, can run in my laptop for a specific case, but can't get accepted
private:
    struct Trie {
        bool ifExist;
        Trie *child[26];
        Trie(): ifExist(false) {
            for (int i = 0; i < 26; i++) child[i] = nullptr;
        }
    };

    void initialize_Trie(Trie *&trie, vector<string>& words) {
        for (auto word: words) {
            Trie *current = trie;
            for (int i = 0; i < word.size(); i++) {
                int pos =  word[i] - 'a';
                if (!current->child[pos]) current->child[pos] = new Trie();
                current = current->child[pos];
            }
            current->ifExist = true;
        }
    }

public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        vector<string> res;
        int m = board.size();
        if (m == 0) return res;
        int n = board[0].size();
        if (n == 0) return res;
        if (words.size() == 0) return res;

        Trie *trie = new Trie();
        initialize_Trie(trie, words);

        unordered_set<int> trace; 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                backtracking(board, trie, "", i, j, m, n, res);
            }
        }
        return res;
    }

    // unordered_set doesn't support pair, use int instead, this 
    // void backtracking(vector<vector<char> >& board, Trie* trie, string word, unordered_set<int> trace, int i, int j, int m, int n, vector<string> &res) {
        
    //     if (i >= 0 && i < m && j >= 0 && j < n && trace.count(n * i + j) == 0) {
    //         word += board[i][j];
    //         trace.insert(n * i + j);
    //         if (!ifPrefix(trie, word)) return;
    //         if (match(trie, word)) {
    //             res.push_back(word);
    //             return;
    //         }
    //         backtracking(board, trie, word, trace, i + 1, j, m, n, res);
    //         backtracking(board, trie, word, trace, i - 1, j, m, n, res);
    //         backtracking(board, trie, word, trace, i, j + 1, m, n, res);
    //         backtracking(board, trie, word, trace, i, j - 1, m, n, res);
    //     } 
    // }

    void backtracking(vector<vector<char> > &board, Trie* trie, string word, int i, int j, int m, int n, vector<string> &res) {
        if (i >= 0 && i < m && j >= 0 && j < n) {
            word += board[i][j];
            if (!ifPrefix(trie, word)) return;
            if (match(trie, word)) {
                res.push_back(word);
                return;
            }
            char temp = board[i][j];
            board[i][j] = 'V'; // change it as visited, great idea
            backtracking(board, trie, word, i + 1, j, m, n, res);
            backtracking(board, trie, word, i - 1, j, m, n, res);
            backtracking(board, trie, word, i, j + 1, m, n, res);
            backtracking(board, trie, word, i, j - 1, m, n, res);
            board[i][j] = temp; // recover from it

        } 
    }

    bool match(Trie* trie, string word) { // one trie trace "oath", word "oat" => return false
        for (auto c: word) {
            int pos = c - 'a';
            if (!trie->child[pos]) return false;
            trie = trie->child[pos];
        }
        if (trie->ifExist) {
            trie->ifExist = false; // avoid repeating
            return true;

        }
        return false;
    }

    bool ifPrefix(Trie* trie, string word) {  // one trie trace "oath", word "oat" => return true
        for (auto c: word) {
            int pos = c - 'a';
            if (!trie->child[pos]) return false; // return false if the path doesn't even exist
            trie = trie->child[pos];
        }
        return true;
    }
};


// Others' method
class Trie {
public:
    struct TrieNode {
        TrieNode* nodes[26];
        bool isEnd;
        TrieNode() { 
            for (int i = 0; i < 26; i++)
                nodes[i] = NULL;
            isEnd = false; 
        }
};

    Trie() { root = new TrieNode(); }
    TrieNode* getRoot() { return root; }

    void addString(string s) {
        TrieNode* t = root;
        for (int i = 0; i<s.length(); i++) {
            if (t->nodes[s[i] - 'a'])
                t = t->nodes[s[i] - 'a'];
            else {
                TrieNode* n = new TrieNode();
                t->nodes[s[i] - 'a'] = n;
                t = n;
            }
        }
        t->isEnd = true;
    }

    TrieNode* moveNext(TrieNode* t, char c) {
        return t->nodes[c - 'a'];
    }

    private:
       TrieNode* root;
};



class Solution2 {
    Trie t;

    void findWords(vector<string>& result, vector<vector<char>>& board, Trie::TrieNode* root, int row, int col, string str) {
        root = t.moveNext(root, board[row][col]);

        if (root) {
            if (root->isEnd) {
                result.push_back(str + board[row][col]);
                root->isEnd = false;
            }

            char c = board[row][col];
            board[row][col] = 'X';
            
            if (col - 1 >= 0 && board[row][col - 1]) 
                findWords(result, board, root, row, col - 1, str + c);
            if (row - 1 >= 0 && board[row - 1][col]) 
                findWords(result, board, root, row - 1, col, str + c);
            if (col + 1 < board[row].size() && board[row][col + 1]) 
                findWords(result, board, root, row, col + 1, str + c);
            if (row + 1 < board.size() && board[row + 1][col]) 
                findWords(result, board, root, row + 1, col, str + c);

            board[row][col] = c;
        }
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i = 0; i<words.size(); i++)
            t.addString(words[i]);

        vector<string> result;
        for (int i = 0; i<board.size(); i++)
            for (int j = 0; j < board[i].size(); j++) 
                findWords(result, board, t.getRoot(), i, j, "");
        return result;
      }
};


int main() {
    Solution2 s;
    Examples eg;
    // vector<string> words = {"cdba", "ab", "bdc"};
    // vector<vector<char> > board = {{'a', 'b'},
    //                                {'c', 'd'}};
    // // vector<string> words = {"aaaaaaaaaaaaa", "aaaaaaaaaaaa"};
    // // vector<vector<char> > board = {{'a', 'a', 'a', 'a'},
    // //                                {'a', 'a', 'a', 'a'},
    // //                                {'a', 'a', 'a', 'a'}};

    // my own solution failed in the following case, but the answer is right compared to others' version
    vector<vector<char> > board = {{'b','a','a','b','a','b'},
                                   {'a','b','a','a','a','a'},
                                   {'a','b','a','a','a','b'},
                                   {'a','b','a','b','b','a'},
                                   {'a','a','b','b','a','b'},
                                   {'a','a','b','b','b','a'},
                                   {'a','a','b','a','a','b'}};
    vector<string> words = {"bbaabaabaaaaabaababaaaaababb","aabbaaabaaabaabaaaaaabbaaaba","babaababbbbbbbaabaababaabaaa","bbbaaabaabbaaababababbbbbaaa","babbabbbbaabbabaaaaaabbbaaab","bbbababbbbbbbababbabbbbbabaa","babababbababaabbbbabbbbabbba","abbbbbbaabaaabaaababaabbabba","aabaabababbbbbbababbbababbaa","aabbbbabbaababaaaabababbaaba","ababaababaaabbabbaabbaabbaba","abaabbbaaaaababbbaaaaabbbaab","aabbabaabaabbabababaaabbbaab","baaabaaaabbabaaabaabababaaaa","aaabbabaaaababbabbaabbaabbaa","aaabaaaaabaabbabaabbbbaabaaa","abbaabbaaaabbaababababbaabbb","baabaababbbbaaaabaaabbababbb","aabaababbaababbaaabaabababab","abbaaabbaabaabaabbbbaabbbbbb","aaababaabbaaabbbaaabbabbabab","bbababbbabbbbabbbbabbbbbabaa","abbbaabbbaaababbbababbababba","bbbbbbbabbbababbabaabababaab","aaaababaabbbbabaaaaabaaaaabb","bbaaabbbbabbaaabbaabbabbaaba","aabaabbbbaabaabbabaabababaaa","abbababbbaababaabbababababbb","aabbbabbaaaababbbbabbababbbb","babbbaabababbbbbbbbbaabbabaa"};
    printVector(s.findWords(board, words));                               
}

