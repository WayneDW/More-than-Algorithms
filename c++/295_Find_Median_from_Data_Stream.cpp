#include <iostream>
#include <vector>
#include <map>
#include <set>
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

/*Median is the middle value in an ordered integer list. If the size of the list is even, 
there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2*/

class MedianFinder { // passable, simple but extremly slow
    priority_queue<int> small, large;
public:
    void addNum(int num) {
        // large size is no less than small
        if (large.size() > small.size()) {
            large.push(-num);
            small.push(-large.top()); large.pop();
        }
        else {
            small.push(num);
            large.push(-small.top()); small.pop();
        }

    }
    double findMedian() {
        return small.size() == large.size()? (small.top() - large.top()) / 2.0f: -large.top();
        // return small.size() == large.size()? double(small.top() - large.top()) / 2: -large.top();
    }
};


class MedianFinder_SORT_VEC { // faster
public:
    // Adds a number into the data structure.
    vector<int> v;
    void addNum(int num) {
        int low = 0,high = (int)(v.size()) - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(v[mid] < num) low=mid + 1;
            else high = mid - 1;
        }
        v.insert(v.begin() + low,num);
    }

    // Returns the median of current data stream
    double findMedian() {
        double res = 0;
        if(v.size() % 2 == 0){
            res=(v[v.size() / 2] + v[v.size() / 2 - 1]);
            res /= 2.0f; // nice way
        }
        else res=v[v.size() / 2];
        return res;
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

int main() {
    MedianFinder s;
    Examples eg;
    s.addNum(1);
    s.addNum(2);
    // cout << s.findMedian() << endl;
    s.addNum(3);
    cout << s.findMedian() << endl;
}
