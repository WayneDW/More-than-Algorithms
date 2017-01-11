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


// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const; // const member function: not modify the object or call any non-const member functions
};


class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return Iterator(*this).next(); // don't fully understand this part. need advanced OOP knowledge
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        return Iterator::next();
    }

    bool hasNext() const {
        return Iterator::hasNext();
    }
};

class PeekingIterator : public Iterator {
private:
    int m_next;
    bool m_hasnext;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        m_hasnext = Iterator::hasNext();
        if (m_hasnext) m_next = Iterator::next();
    }

    int peek() {
        return m_next;
    }

    int next() {
        int t = m_next;
        m_hasnext = Iterator::hasNext();
        if (m_hasnext) m_next = Iterator::next();
        return t;
    }

    bool hasNext() const {
        return m_hasnext;
    }
};

int main() {
    // Solution s;
    Examples eg;
    int a = 1;
    int &b = a;
    a = 2;
    b = 3;
    cout << a << endl;
    cout << &b << endl;

}
