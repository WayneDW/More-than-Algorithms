#include <iostream>
#include <vector>
#include <typeinfo>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

template <class types>
void print(vector<types> vec) {
    for (auto v: vec) cout << v << " ";
    cout << endl;
}

template <class types>
void print(vector<vector<types> > vec) {
    for (auto v: vec) {
        for (auto p: v) cout << p << " ";
        cout << endl;
    }
    cout << endl;
}

template <class types>
void print(vector<pair<types, types> > vec) {
    for (auto v: vec) cout << "(" << v.first << ","  << v.second << ")" << " ";
    cout << endl;
}

template <class types>
void print(map<types, types> mp) {
    for (auto it: mp) cout << "(" << it.first << ","  << it.second << ")" << " ";
    cout << endl;
}

template <class types>
void print(unordered_map<types, types> mp) {
    for (auto it: mp) cout << "(" << it.first << ","  << it.second << ")" << " ";
    cout << endl;
}

template <class types>
void print(multimap<types, types> mp) {
    for (auto it: mp) cout << "(" << it.first << ","  << it.second << ")" << " ";
    cout << endl;
}

template <class types>
void print(set<types> st) {
    for (auto it: st) cout << it << " ";
    cout << endl;
}

template <class types>
void print(unordered_set<types> st) {
    for (auto it: st) cout << it << " ";
    cout << endl;
}

template <class types>
void print(multiset<types> st) {
    for (auto it: st) cout << it << " ";
    cout << endl;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Examples {
public:
    TreeNode *setTree0(){
        TreeNode *t0 = new TreeNode(1);
        TreeNode *t1 = new TreeNode(2);
        TreeNode *t2 = new TreeNode(3);
        TreeNode *t3 = new TreeNode(4);
        TreeNode *t4 = new TreeNode(5);
        TreeNode *t5 = new TreeNode(6);
        TreeNode *t6 = new TreeNode(7);
        t0->left = t1;
        t0->right = t2;
        t1->left = t3;
        t1->right = t4;
        t2->left = t5;
        t2->right = t6;
        return t0;
    }
};
