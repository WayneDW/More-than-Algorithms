#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

template <class types>
void print1dVector(vector<types> vec) {
    for (int i = 0; i < vec.size(); i++) {

        cout << vec[i] << " ";
    }
    cout << endl;
}



template <class types>
void print2dVector(vector<vector<types> > vec) {
    for (int i = 0; i < vec.size(); i++)
        print1dVector(vec[i]);
}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};