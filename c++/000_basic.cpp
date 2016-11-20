#include <iostream>
#include <vector>
#include <typeinfo>

using namespace std;

template <class types>
void printVector(vector<types> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

template <class types>
void printVector(vector<vector<types> > vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++)
                cout << vec[i][j] << " ";
        cout << endl;
    }
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
