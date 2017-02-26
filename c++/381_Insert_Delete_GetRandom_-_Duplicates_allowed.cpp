#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <numeric>
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

/*Design a data structure that supports all following operations in average O(1) time.

Note: Duplicate elements are allowed.
insert(val): Inserts an item val to the collection.
remove(val): Removes an item val from the collection if present.
getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
Example:

// Init an empty collection.
RandomizedCollection collection = new RandomizedCollection();

// Inserts 1 to the collection. Returns true as the collection did not contain 1.
collection.insert(1);

// Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
collection.insert(1);

// Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
collection.insert(2);

// getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
collection.getRandom();

// Removes 1 from the collection, returns true. Collection now contains [1,2].
collection.remove(1);

// getRandom should return 1 and 2 both equally likely.
collection.getRandom();*/

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        vec.push_back(val);
        mp[val].insert(vec.size() - 1);
        return mp[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. 
    

    vec             [ 1  2  2  4  5   3   4]

    hash              1    2     3    4    5
                    {0}  {1,2}  {5} {3,6}  {4}


    vec             [ 1  2  4  4  5   3]

    hash              1  2     3      4   5
                     {0} {1}  {5}   {2,3} {4}

    to del 2 we replace 4 with 2, update the new position for 4 and also for 2
    pop the last vector of vec and erase the value in hash*/

    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        int pos_tar = *(mp[val].rbegin()); // use back position use we replace the target with the last element
        vec[pos_tar] = vec.back();
        mp[vec.back()].erase(*(mp[vec.back()].rbegin()));
        mp[vec.back()].insert(pos_tar);
        if (mp[val].size() == 1) mp.erase(val);
        else mp[val].erase(*(mp[val].rbegin()));
        vec.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return vec[rand() % vec.size()];
    }
private:
    vector<int> vec;
    unordered_map<int, set<int>> mp; // unordered_set doesn't have reverse iterator
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */



int main() {
    Solution s;
    Examples eg;
}
