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

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. Each element must have the same 
probability of being returned.
Example:

// Init an empty set.
RandomizedSet randomSet = new RandomizedSet();

// Inserts 1 to the set. Returns true as 1 was inserted successfully.
randomSet.insert(1);

// Returns false as 2 does not exist in the set.
randomSet.remove(2);

// Inserts 2 to the set, returns true. Set now contains [1,2].
randomSet.insert(2);

// getRandom should return either 1 or 2 randomly.
randomSet.getRandom();

// Removes 1 from the set, returns true. Set now contains [2].
randomSet.remove(1);

// 2 was already in the set, so return false.
randomSet.insert(2);

// Since 2 is the only number in the set, getRandom always return 2.
randomSet.getRandom();*/



// take care, we need o(1) time complexity, thus only hashmap can hardly work

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        vec.push_back(val);
        mp[val] = vec.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    /*
        vec      1 2 5 4
        
        hash     1 2 5 4
                 | | | |
                 v v v v
                 0 1 2 3

        to del 5, the idea is to replace 5 with 4, and del the last element 4
                 first we need to know the location of 5 which is 2
                 then replace position of 5 with 4 and update mp[4] = mp[5]
                 then del mp[5]
        we remove position 4, and set 4 in position 3 */

    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        // move the last value in vector to the target position and del the last element
        int loc = mp[val];
        int last = vec.back();
        vec[loc] = last;
        mp[last] = mp[val];
        mp.erase(val);
        vec.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return vec[rand() % vec.size()];
    }
private:
    unordered_map<int, int> mp;
    vector<int> vec;
};

int main() {
    RandomizedSet* s = new RandomizedSet();
    bool param_1 = s->insert(1);
    bool param_2 = s->insert(2);
    // bool param_3 = s->remove(2);
    cout << s->getRandom() << endl;
}
