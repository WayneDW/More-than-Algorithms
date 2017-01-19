# leetCodeOJ in C++ and Python


### Generate framework 

```python
./framework.py 19
```
Let's deal with 19_Remove_Nth_Node_From_End_of_List
```
19_Remove_Nth_Node_From_End_of_List.cpp generated successfully! 
```
If some file already existed, do nothing in that file
```python
./framework.py 19
```

```
>> Let's deal with 19_Remove_Nth_Node_From_End_of_List
19_Remove_Nth_Node_From_End_of_List.cpp already existed!
```

### Upload script

Type in the question number and the commit words as the rest of the parameters
```
./upload.sh 19 Linked List double pointer
```

### Notes in C++, [tutorial](http://www.learncpp.com/)

The memory a program uses typically contains the following areas: 
* code segment, where the compiled program sits in memory
* bss segment, where zero-initialized **global** and **static variables** are stored.
* data segment, where initialized **global** and **static variables** are stored
* heap segment, where **dynamically allocated variables** are allocated, allocated **memory stays** allocated until it is specifically deallocated
  * Pros: a big pool of memory
  * Cons: comparatively slow
* call stack: function parameters, local variables, and other function-related information are stored, **destroyed** when it is popped off the stack, recursion is happened here (thus recursion depth is limited number)
  * Pros: fast
  * Cons: small memory, 1~8 MB


Const/Int poiner
```c++
//read it backwards (as driven by Clockwise/Spiral Rule)...
int* // pointer to int
int const * // pointer to const int
int * const // const pointer to int, initialized at first
int const * const // const pointer to const int, initialized at first

//Now the first const can be on either side of the type so:
const int * == int const *
const int * const == int const * const
```

inline
```c++
// pros: speed up execution of a C++ function, best for short function
// cons: compiled code quite a bit larger
inline int min(int x, int y) {
    return x > y ? y : x;
}
```

Reference/Pointer
```c++
/*reference: 
1. a new name for an object, doesn't exist indeed
2. must be initialized
3. can't reassigned to NULL; 
pointer: 
1. an actual object
2. can be uninitialized
3. can be reassigned*/
```

```c++
int a = 1;
int &b = a;
/*declare a variable, and set b = a, (similar to int *p = &a, declare *p, and set p = &a) 
while here we set a's address to b's address, thus they have the same value; however 
if we use int a = b, despite they have the same value, they have difference addresses*/
cout << b << " ";
a = 2;
cout << b << endl;
>> 1 2
```
```c++
void add(int a, int &c, int *p) {c = a; *p = 2;}
int main() {
    int a = 0, b;
    add(1, a, &b);
    cout << a << " " << b << endl;
}
>> 1 2
```

Declare a pointer to a function
```c++
int sum(int a, int b) {return a + b;}
int main() {
    int (*p)(int, int); // keep (*p)
    p = &sum;
    cout << (*p)(1,2) << endl;
}
>> 3
```
Static
```c++
/* http://www.learncpp.com/cpp-tutorial/811-static-member-variables*/
/* inside a class: only one copy, shared by all objects of the class*/
class Something{
public:
    static int s_value;
};
// a good case is #[279](discuss.leetcode.com/topic/23812/static-dp-c-12-ms-python-172-ms-ruby-384-ms/6)
int Something::s_value = 1; 
/* Because static member variables are not part of the individual class objects (they get initialized
when the program starts), you must explicitly define the static member outside of the class */
int main(){
    Something first;
    Something second;
 
    second.s_value = 2;
 
    std::cout << first.s_value << " " << second.s_value << '\n';
    return 0;
}
>> 2 2
```
```c++
/* inside a file: private in the file */
/* inside a function*/
void func() {
    static int x = 0; 
    /* x is initialized only once across five calls of func() and the variable will get 
    incremented five times after these calls. The final value of x will be 5. */
    x++;
    printf("%d\n", x); // outputs the value of x
}

int main() { //int argc, char *argv[] inside the main is optional in the particular program
    func(); // prints 1
    func(); // prints 2
}
```


Linked List, e.g. 328
```c++
void deleteNode(ListNode* node) {
    *node = *node->next; // this may suffer from memory leaking
}
```
We should delete the next node:
```c++
void deleteNode(ListNode* node) {
    auto next = node->next;
    *node = *next; // here the copy considers the pointer and address
    delete next;
}
```


```c++
for (auto i : v) // access by value, the type of i is int
for (auto&& i : v) // access by reference, the type of i is int&
```
map, unordered_map
```c++
for(map<int, int>::iterator iter = dt.begin(); iter != dt.end(); ++iter) {
    int k = iter->first;
    int v = iter->second;
}
```

set
```c++
for (set<int> itr  = os.begin(); itr != os.end() ; ++itr) 
    cout << *itr << endl;
// for c++11 or later
for (auto item : os)
    cout << item << endl;
```

Vector, List, Deque
```c++
List: doubly linked list
Deque: doubly queue
```

Customized sort function, e.g. 219
```c++
static bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}
sort(vec.begin(), vec.end(), cmp);
```

Bitwise operation

```c++
Symbol  Operator
&   bitwise AND
|   bitwise inclusive OR
^   bitwise XOR (eXclusive OR)
<<  left shift
>>  right shift
~   bitwise NOT (one's complement) (unary)
```
```c++
    0101 (decimal 5)
XOR 0011 (decimal 3)
  = 0110 (decimal 6)

```
[Bit flag](http://www.learncpp.com/cpp-tutorial/3-8a-bit-flags-and-bit-masks/)

```c++
// in c++11 use uint8_t instead of unsigned char
const unsigned char option4 = 0x08; // hex for 0000 1000
// Here 0x stands for hexadecimal number
// 3 = 0011 (binary)
// F = 15 (base 10) = 1111 (binary)
// 0x3FFFFFFF = 0011 1111 1111 1111 1111 1111 1111 1111
if (myflags & option4) ... // if option4 is set, do something
myflags |= option4; // turn option 4 on.
myflags |= option4 | option5; // turn options 4 and 5 on.
myflags &= ~option4; // turn option 4 off
myflags ^= option4; // flip option4 from on to off, or vice versa
```



```c++
int a = 1;
if (1 > 0)
    int a = 2; // no mistake, but don't work
// print 1

int a = 1;
int a = 2; // mistake
```

To avoid overflow
```c++
p = (unsigned long long) p * m / n ...
```

String
```c++
string.substr(2, 2) # abcdefg -> cd
string.substr(2) # abcdefg -> cdefg

string.push_back('a');
string.append("abc");
```
```c++
queue<TreeNode*> rather than queue<TreeNode>
```

Vector Initialization
```c++
vector<int> vec(10, 1); // initialize 10 number of 1
vector<int> vec(10); // initialize 10 number of 0
vector<vector<int> > vec(2, vector<int>(2, INT_MAX)); // 2d initialization

// simple way to initialization
vector<int> v = {0, 1, 2, 3, 4, 5}; // good way
vec.push(vector<int>{0, 1, 2, 3, 4, 5});
int dat[] = {0, 1};
vector<int> vec(dat, dat + sizeof(dat) / sizeof(int)); // unwieldy way
```

Vector operation, constant insertion at the end, o(n) otherwise
```c++
vec.erase(vec.begin() + 1); // delete the 2nd element
vec.erase(vec.end() - 1); // erase the last element
vec.erase(vec.begin(), vec.begin() + 2); // delete the first 2 elements
vec.insert(vec.begin(), tmp); // insert value at the beginning

for (int i = 0; i < vec.size(); i++)  // wrong way if we do vector operations in the loop

int len = vec.size();
for (int i = 0; i < len; i++)
    ***
```

istringstream
```c++
// convert ostringstream to a set of variables
istringstream s(string); // to initialize
int val; // or other types
s >> val; // set value
if (! (s >> val)) // to determine if it has reached the end
```

ostringstream 
```c++
// convert output (analogy) to string
see example c++ 165, 297
```
pass by reference/ value

```c++
Overhead with passing by reference:

each access needs a dereference, i.e., there is one more memory read
Overhead with passing by value:

the value needs to be copied on stack or into registers
For small objects, such as an integer, passing by value will be faster. 

For bigger objects (for example a large structure), the copying would create too much overhead so passing by reference will be faster. e.g. 307, pass nums by reference greatly increase speed.
```


struct initialization
```c++
struct Interval {
    int start, end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
```

convert string to int
```c++
stoi
```



null pointer in C++11
```c++
nullptr
```

multimap v.s. map, key difference: we can have multiple keys
```c++
multimap<int, int> mp;
mp.emplace(1, 2);
mp.emplace(1, 3);
print(mp);
>> (1, 2) (1, 3)
```

priority_queue
```c++
priority_queue<int> pq(nums.begin(), nums.end());
for (int i = 0; i < k - 1; i++)
    pq.pop(); 
int topK = pq.top();
```

public/protected/private
```c++
public: anyone can access
protected: member, friends and subclass
private: member and friends.
```

for loop
```c++
for (i = 0, res += 1; i < 0; i++) // this res adds 1
for (int i = 0, res += 1; i < 0; i++) // this res doesn't add 1
```

return
```c++
// funtion pass by reference of dict
return dict[4] = 5;
// this returns 5 and update the dict
```

### Objected Oriented Programming

```c++
class Base {
public:
    int m_public; // can be accessed by anybody
private:
    int m_private; // can only be accessed by Base members and friends (but not derived classes)
protected:
    int m_protected; // can be accessed by Base members, friends, and derived classes
};
 
class Derived: public Base {
public:
    Derived() {
        m_public = 1; // allowed: can access public base members from derived class
        m_private = 2; // **not allowed**: can not access private base members from derived class
        m_protected = 3; // allowed: can access protected base members from derived class
    }
};
 
int main() {
    Base base;
    base.m_public = 1; // allowed: can access public members from outside class
    base.m_private = 2; // not allowed: can not access private members from outside class
    base.m_protected = 3; // **not allowed**: can not access protected members from outside class
}

class Base {
public:
    int m_public;
private:
    int m_private;
protected:
    int m_protected;
};
 
class Pri: Base { // note: private inheritance
public:
    Pri() {
        m_public = 1; // okay: m_public is now private in Pri
        m_private = 2; // not okay: derived classes can't access private members in the base class
        m_protected = 3; // okay: m_protected is now private in Pri
    }
};
 
int main() {
    // Outside access uses the access specifiers of the class being accessed.
    // In this case, the access specifiers of base.
    Base base;
    base.m_public = 1; // okay: m_public is public in Base
    base.m_private = 2; // not okay: m_private is private in Base
    base.m_protected = 3; // not okay: m_protected is protected in Base
 
    Pri pri;
    pri.m_public = 1; // **not okay**: m_public is now private in Pri
    pri.m_private = 2; // not okay: m_private is inaccessible in Pri
    pri.m_protected = 3; // not okay: m_protected is now private in Pri
}
```

Member initializer lists can initialize const
```c++
int value1 = 1; // copy initialization
double value2(2.2); // direct initialization
char value3 {'c'} // uniform initialization, 
//Rule: favor uniform initialization over direct initialization if you compiler is C++11 compatible

class Something {
private:
    const int m_value;
 
public:
    Something(): m_value(5) { // directly initialize our const member variable
    } 
};
```
this pointer enables Chaining objects
```c++
// *this is a const pointer, you can change the value it points to, but not pointing somethere else
class Calc {
private:
    int m_value;
 
public:
    Calc() { m_value = 0; }
    Calc& add(int value) { m_value += value; return *this; }
    Calc& sub(int value) { m_value -= value; return *this; }
    int getValue() { return m_value; }
};

#include <iostream>
int main() {
    Calc calc;
    calc.add(5).sub(3);
    std::cout << calc.getValue() << '\n';
    return 0;
}
```
seperating .cpp and .h
* recompile it every time you need it
* avoid people stealing your code

Inheritance
```c++
class A {
public:
    A(double x) { cout << "A " << x << endl; }
};
 
class B: public A {
public:
    B(int x) { cout << "B " << x << endl;}
};

int main() {
    B cB(5); 
}
>> A 5 // since base constructor is used first
```

Member initializer lists can initialize const
```c++
int value1 = 1; // copy initialization
double value2(2.2); // direct initialization
char value3 {'c'} // uniform initialization, 
//Rule: favor uniform initialization over direct initialization if you compiler is C++11 compatible

class Something {
private:
    const int m_value;
 
public:
    Something(): m_value(5) { // directly initialize our const member variable
    } 
};
```
this pointer enables Chaining objects
```c++
// *this is a const pointer, you can change the value it points to, but not pointing somethere else
class Calc {
private:
    int m_value;
 
public:
    Calc() { m_value = 0; }
    Calc& add(int value) { m_value += value; return *this; }
    Calc& sub(int value) { m_value -= value; return *this; }
    int getValue() { return m_value; }
};

#include <iostream>
int main() {
    Calc calc;
    calc.add(5).sub(3);
    std::cout << calc.getValue() << '\n';
    return 0;
}
```

seperating .cpp and .h
* recompile it every time you need it
* avoid people stealing your code

A const member function is a member function that guarantees it will not modify the object or call any non-const member functions (as they may modify the object).
```c++
int getValue() const { return m_value; }
```

static member variable
```c++
/* inside a class: only one copy, shared by all objects of the class*/
class Something{
public:
    static int s_value;
};
// a good case is #[279](discuss.leetcode.com/topic/23812/static-dp-c-12-ms-python-172-ms-ruby-384-ms/6)
int Something::s_value = 1; 
/* Because static member variables are not part of the individual class objects (they get initialized
when the program starts), you must explicitly define the static member outside of the class */
int main(){
    Something first;
    Something second;
 
    second.s_value = 2;
 
    std::cout << first.s_value << " " << second.s_value << '\n';
    return 0;
}
>> 2 2
```
static member function
it has no *this pointer, we can use it without initializing the class
```c++
class sample {
public:
    static int getNextID() {return 1;}    
};

int main() {
    IDGenerator::getNextID();
}
```
enum class
```c++
enum FruitType {
    APPLE,
    BANANA
};
```

Polymorphism

```c++
class Base {
public:
    virtual void print() { cout << "Base" << endl;}
};
class Derived : public Base {
public:
    virtual void print() { cout << "Derived" << endl; }
};
int main() {
    Derived d;
    Base *b = &d;
    b->print(); // print Derived, with virtual, otherwise Base
}
```

* override: if the function does not override a base class function, the compiler will return an error.
* final: restrict the user from overriding a function

```c++
case 1: 
class B final : public A { // note use of final specifier here
public:
    virtual const char* getName() override { return "B"; }
};
case 2:
virtual const char* getName() override final { return "B"; }
```

Whenever you are dealing with inheritance, you should make any explicit destructors virtual.
```c++
>> Calling ~Derived()
>> Calling ~Base()
```

A** pure virtual function** makes it so the base class can not be instantiated, and the derived classes are **forced** to define these function before they can be instantiated. This helps ensure the **derived classes do not forget to redefine functions** that the base class was expecting them to.

```c++
virtual int getValue() = 0; // a pure virtual function
```

An interface class is a class that has no member variables, and where all of the functions are pure virtual!

object slicing
```c++
// ref references and ptr points to derived. Because ref and ptr are of type Base, ref and ptr can only see the Base part of derived. However, through use of virtual functions, we can access that function
Base &ref = derived;
Base *ref = &derived;
Base base = derived; // only the Base portion of the Derived object is copied
```
Note: try to avoid any kind of pass-by-value when it comes to derived classes


dynamic_cast: mainly used to convert base-class pointers into derived-class pointers (**downcasting**)
```c++
Base *b = new Derived(1, "Apple");
Derived *d = dynamic_cast<Derived*>(b); // use dynamic cast to convert Base pointer into Derived pointer
if (d) // make sure d is non-null
    std::cout << "The name of the Derived is: " << d->getName() << '\n';
```

dynamic_cast vs static_cast
* use dynamic_cast for downcasting
* use static_cast otherwise, faster and dangerous
* In a word, avoid using them altogether, use virtual function instead

### Notes in python

```python
>>> b = []
>>> a = [1]
>>> b.append(a)
>>> a.pop()
>>> b
[[]]
```

Tips in iterables, generators, yield
http://stackoverflow.com/questions/231767what-does-the-yield-keyword-do
Iterables
```python
>>> mylist = [1, 2, 3]
>>> for i in mylist:
...    print(i)
1
2
3
```

Generators: iterators, but you can only iterate over them once. It's because they do not store all the values in memory, they generate the values on the fly:
```python
>>> mygenerator = (x*x for x in range(3))
>>> for i in mygenerator:
...    print(i)
0
1
4
```

Yield: a keyword that is used like return, except the function will return a generator.
```python
>>> def createGenerator():
...    mylist = range(3)
...    for i in mylist:
...        yield i*i
...
>>> mygenerator = createGenerator() # create a generator
>>> print(mygenerator) # mygenerator is an object!
<generator object createGenerator at 0xb7555c34>
>>> for i in mygenerator:
...     print(i)
0
1
4

```


### Notes in Algorithms

Master Theorem
```
T(n) = aT(n/b) + n^c
denote d = log(a) / log(b)
then time complexity is as follows
// intuitive thinking: when d = c, the problem has log(n) layers with n^c complexity in each
i,   c = d --> o(n^d * log(n))  
ii,  c < d --> o(n^d)
iii, c > d --> o(n^c)
```

Bucket sort, e.g. Q164
```
    Given the MIN and MAX of the array, the gap between MIN and MAX is MAX-MIN, there are n-1 intervals, so the largest
    interval length, denoted as maxGap, must be larger than ceiling[(MAX-MIN)/(n-1)]

    We construct several buckets with length maxGap, each one is close to another. e.g. [5,1,3,2,4,10]

    Bucket 
       0   1    2    3
    |____|____|____|___|
    1   3|4  6|7  9|10

    we put the numbers into its corresponding bucket

    Min 1 2   4         10
    Max     3   5       10
        |____|____|____|___|
        1   3|4  6|7  9|10
```

Binary Search, easy to make mistakes in the corner case
```c++
int binarySearch(vector<int> nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2; // a very good way
        if (nums[mid] == target) return target;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
 }
 ```
KMP algorithm

Segment Tree

Red Black Tree
 

