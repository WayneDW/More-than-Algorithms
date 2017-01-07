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

/*Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing 
only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true*/


class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        Trie* cur = root;
        for (auto c: word) {
            if (!cur->child[c - 'a']) cur->child[c - 'a'] = new Trie(); // by default, they are NULLs
            cur = cur->child[c - 'a']; // this assumes the children exist, however, by default, they are NULLs
        }
        cur->key = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return query(word, root);
        // return query(word.c_str(), root);
    }
private:
    
    struct Trie {
        bool key;
        Trie* child[26];
        Trie(): key(false) {for (int i = 0; i < 26; i++) child[i] = NULL;}
    };
    Trie* root = new Trie();


    bool query(string word, Trie* node) {
        for (int i = 0; i < word.size(); ++i) {
            if (node && word[i] != '.') node = node->child[word[i] - 'a'];
            else if (node && word[i] == '.') {
                char bak = word[i];
                for (int j = 0; j < 26; j++) {
                    word[i] = 'a' + j;
                    string sub = word.substr(i, word.size() - i);
                    if (query(sub, node)) {
                        return true;
                    }
                    word[i] = bak;
                }
                return false; // important, e.g. addword("a"), search(".a"), without this, we may run 2nd word a and give right solution
            }
            else break;
        }
        return node && node->key;
    }
    


    bool query(const char* word, Trie* node) {
        for (int i = 0; word[i]; i++) {
            if (node && word[i] != '.') node = node->child[word[i] - 'a'];
            else if (node && word[i] == '.') { 
                Trie* bak = node;
                for (int j = 0; j < 26; j++) {
                    node = bak -> child[j];
                    if (query(word + i + 1, node))
                        return true;
                }
            }
            else break;
        }
        return node && node -> key; 
    }
};


    // bool query2(string word, Trie* node) {
    //     Trie* run = node;
    //     for (int i = 0; i < word.size(); i++) {
    //         if (run && word[i] != '.') run = run -> child[word[i] - 'a'];
    //         else if (run && word[i] == '.') { 
    //             Trie* tmp = run;
    //             for (int j = 0; j < 26; j++) {
    //                 run = tmp -> child[j];
    //                 string sub = word.substr(i + 1, word.size() - i - 1);
    //                 if (query(sub, run))
    //                     return true;
    //             }
    //         }
    //         else break;
    //     }
    //     return run && run -> key; 
    // }

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");



int main() {
    WordDictionary s;
    Examples eg;
    s.addWord("a"); 
    s.addWord("a"); 
    cout << s.search(".a") << endl;
}
