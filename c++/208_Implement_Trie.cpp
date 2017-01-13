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
#include "func.cpp"

using namespace std;

class TrieNode {
public:
    TrieNode* child[26]; // a pointer to an array of 26 integers
    bool type;
    // Initialize your data structure here.
    TrieNode(): type(NULL)  {
        for (auto &a : child) a = NULL;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* p = root;
        for (auto a : word) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->type = true; // tag the end of string
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* p = root;
        for (auto a : word) {
            int i = a - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        }
        return p->type; // may not be the end
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* p = root;
        for (auto a : prefix) {
            int i = a - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main() {
    Trie s;
    Examples eg;
}
