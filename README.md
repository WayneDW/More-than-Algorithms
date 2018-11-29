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


const/Int poiner
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

inline v.s. macro
* they are both used to avoid function calls
* inline is parsed by compiler, macro is expanded by the preprocessor
* macro may be harder debug, see [here](http://www.programmerinterview.com/index.php/c-cplusplus/inline-vs-macro/), thus inline is easier

```c++
#define MAX(a, b) a > b? a: b
```

```c++
// pros: speed up execution of a C++ function, best for short function
// cons: compiled code quite a bit larger
inline int min(int x, int y) {
    return x > y ? y : x;
}
```

reference/pointer
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

declare a pointer to a function
```c++
int sum(int a, int b) {return a + b;}
int main() {
    int (*p)(int, int); // keep (*p)
    p = &sum;
    cout << (*p)(1,2) << endl;
}
>> 3
```
static
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


linked List, e.g. 328
```c++
void deleteNode(ListNode* node) {
    *node = *node->next; // this may suffer from memory leaking
}
```
we should delete the next node:
```c++
void deleteNode(ListNode* node) {
    auto next = node->next;
    *node = *next; // here the copy considers the pointer and address
    delete next;
}
```

customized sort function, e.g. 219
```c++
static bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second < b.second;
}
sort(vec.begin(), vec.end(), cmp);
```

```c++ 
// https://discuss.leetcode.com/topic/65629/concise-c-solution
auto cmp = []( Interval& a,  Interval& b) {return a.start < b.start; };
sort(intervals.begin(), intervals.end(), cmp);
```

bitwise operation
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
0b1010 // binary representation
```

Bitset
```c++
bitset<16> foo; // foo: 0000000000000000
bitset<16> bar (0xfa2); // bar: 0000111110100010
bitset<16> baz (string("0101111001")); // baz: 0000000101111001

bitset<4> foo;                   // 0000
cout << foo.set() << '\n';       // 1111
cout << foo.set(2,0) << '\n';    // 1011
cout << foo.set(2) << '\n';      // 1111
cout << foo.count() << endl;     // 4
```


parameter in a inner loop
```c++
int a = 1;
if (1 > 0) int a = 2; // no mistake, but don't work
// print 1

int a = 1;
int a = 2; // mistake
```

to avoid **overflow**
```c++
p = (unsigned long long) p * m / n ...
```

pass by reference/ value

```c++
Overhead with passing by reference:

each access needs a dereference, i.e., there is one more memory read
Overhead with passing by value:

the value needs to be copied on stack or into registers
For small objects, such as an integer, passing by value will be faster. 

For bigger objects (for example a large structure), the copying would create too much overhead 
so passing by reference will be faster. e.g. 307, pass nums by reference greatly increase speed.
However, if you end up with copying the data, then passing by value is better.
```


struct initialization
```c++
struct Interval {
    int start, end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};
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

Vector, List, Deque
```c++
List: doubly linked list
Deque: doubly queue
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
    pri.m_public = 1; // not okay: m_public is now private in Pri
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

A const member function is a member function that guarantees it will not modify the 
object or call any non-const member functions (as they may modify the object).
```c++
int getValue() const { return m_value; }
```

copy constructor
```c++
class Solution {
    ...
    // Default constructor
    Fraction(int numerator=0, int denominator=1) :
        m_numerator(numerator), m_denominator(denominator) {
        assert(denominator != 0);
    }
};
```

shallow v.s. deep copying

* shallow copy: C++ copies each member of the class individually
* deep copy: allocates memory for the copy and then copies the actual value

```c++
MyString::MyString(const MyString& source) { // Copy constructor
    // because m_length is not a pointer, we can shallow copy it
    m_length = source.m_length;
 
    // m_data is a pointer, so we need to deep copy it if it is non-null
    if (source.m_data) {
        // allocate memory for our copy
        m_data = new char[m_length];
        // do the copy
        for (int i=0; i < m_length; ++i)
            m_data[i] = source.m_data[i];
    }
    else
        m_data = 0;
}
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
class IDGenerator {
private:
    static int s_nextID; // Here's the declaration for a static member
public:
     static int getNextID() {
         return s_nextID++;
     }
};

int IDGenerator::s_nextID=1;

int main() {
    IDGenerator::getNextID();
    IDGenerator::getNextID();
    return 0;
}
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

A **pure virtual function** makes it so the base class can not be instantiated, and the derived classes 
are **forced** to define these function before they can be instantiated. This helps ensure the **derived
classes do not forget to redefine functions** that the base class was expecting them to.

```c++
virtual int getValue() = 0; // a pure virtual function
```

An interface class is a class that has no member variables, and where all of the functions are pure virtual!

object slicing
```c++
/* ref references and ptr points to derived. Because ref and ptr are of type Base, ref and ptr can only see 
the Base part of derived. However, through use of virtual functions, we can access that function*/
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


#### Template

overload operator when template deals with class

expression parameter
```c++
template <class T, int size> // size is the expression parameter
class StaticArray {
private:
    // The expression parameter controls the size of the array
    T m_array[size];
    ...
}
```

template specialization
```c++
template <> // the following is a template class with no templated parameters
class Storage8<bool> {// we're specializing Storage8 for bool
// What follows is just standard class implementation details
private:
    unsigned char m_data;
    ...
}
```

#### Exception handling
```c++
try {
    throw 4.5; // throw exception of type double
    std::cout << "This never prints\n";
}
catch(double x) { // handle exception of type double
    std::cerr << "We caught a double of value: " << x << '\n' << std::endl;
}
```
stack unwinding
```
try { // Look for exceptions that occur within try block and route to attached catch block(s)
    std::cout << "The sqrt of " << x << " is " << mySqrt(x) << '\n';
}
catch (const char* exception) {// catch exceptions of type const char*
    std::cerr << "Error: " << exception << std::endl;
}
```

Assert v.s. Exception
* Assertion: a statement that something must be true, otherwise flag error
* Exception: the correct functioning of a method isn't met. 

#### Standard Template Library

* sequence container: container classes that maintain the ordering of elements in the container
 * array, deque, string, list
* associative container: automatically sort their inputs when those inputs are inserted into the container.
 * set, multiset, map, multimap
* container adapter: containers that are adapted to specific uses
 * stack, queue, priority_queue

special syntax
* cbegin() returns a const (read-only) iterator representing the beginning of the elements in the container.
* container::iterator provides a read/write iterator
* container::const_iterator provides a read-only iterator

**Vector time complexity**
* Random access - constant O(1)
* Insert/ Delete at the end: constant to delete or insert at the end
* Insert/ Delete otherwise: linear time relative to the distance to the end of the vector

vector operation
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

'->' vs '.'
```c++
object->pointer
object.attribute
```

map erase
```c++
mymap.erase (it.begin());
mymap.erase ( mymap.begin() );      // erasing by iterator
mymap.erase ("France");             // erasing by key
mymap.erase ( mymap.find("China"), mymap.end() ); // erasing by range
```

vector Initialization
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

map, unordered_map
```c++
for(map<int, int>::iterator iter = dt.begin(); iter != dt.end(); ++iter) {
    int k = iter->first;
    int v = iter->second;
}

map
->first !!!!!

unordered_map
iterator  it.first, it.second
// map.rbegin() # from the reverse direction
```

```c++
unordered_map<int, int> mp;
mp[key]++; // don't have to initialize.
```

set
```c++
for (set<int> itr  = os.begin(); itr != os.end() ; ++itr) 
    cout << *itr << endl;
// for c++11 or later
for (auto item : os)
    cout << item << endl;
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


min heap
priority_queue<int, vector<int>, greater<int>> heapq; # quite useful

for (int i = 0; i < k - 1; i++)
    pq.pop(); 
int topK = pq.top();
```

priority_queue custom 

```
struct compare { // this is a functor, real advantage is that a functor can hold state.
    bool operator()(const pair<int,pair<int, int> >& a, const pair<int,pair<int, int> >& b) {
        return a.first>b.first;
    }
};
priority_queue< pair<int,pair<int, int> >, vector<pair<int, pair<int, int> > >, compare > p;
```

```
auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
    return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];};
priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> min_heap(comp);
```

lower_bound & upper_bound
```c++
// [first,last)
// 10 10 10 20 20 20 30 30
            ^
                      ^
```

#### std::string
A big shortcoming of C-style strings is that you have to do all the memory management yourself.

convert string to int
```c++
stoi
```

cerr: an ostream_withassign class tied to the standard error (typically the monitor)
```c++
cerr << "Oops, you entered an invalid age!" << endl;
exit(1);
```

string
```c++
string.substr(2, 2) # abcdefg -> cd
string.substr(2) # abcdefg -> cdefg

string.push_back('a');
string.append("abc");
```
```c++
queue<TreeNode*> rather than queue<TreeNode>
```

#### I/O

getline
```c++
string strBuf;
getline(cin, strBuf);
cout << strBuf << endl;
```

```c++
cout << setprecision(4) << 123.456 << endl; // 123.4560
```
stringstream (**Conversion** between strings and numbers)
```c++
stringstream os;
os << "123 456" << endl;

int val1;
os >> val1; // convert type

string val2;
os >> val2;
```
Clearing a stringstream for reuse
```c++
stringstream os;
os << "Hello ";
 
os.str(""); // or use os.str(string()), erase the buffer
 
os << "World!";
cout << os.str();
```
validation
```c++
isalnum() // Returns non-zero if the parameter is a letter or a digit
isalpha() // Returns non-zero if the parameter is a letter
isdigit() // Returns non-zero if the parameter is a digit
isspace() 
isprint() // Returns non-zero if the parameter is printable character (including whitespace)
isxdigit() // Returns non-zero if the parameter is a hexadecimal digit (0-9, a-f, A-F)
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

**Basic file Output**

```c++
ofstream outf("Sample.dat"); // create a file for writing
outf << "This is line " << endl;
```
**Basic file Input**
```c++
ifstream inf("Sample.dat");
while (inf) {
    // stringstream stm;
    // inf >> stm; // this is indirect
    string strInput;
    getline(inf, strInput);
    cout << stm << endl;
}
```

**Random file I/O**
```c++
inf.seekg(14, ios::cur); // move forward 14 bytes
inf.seekg(-18, ios::cur); // move backwards 18 bytes
inf.seekg(22, ios::beg); // move to 22nd byte in file
inf.seekg(24); // move to 24th byte in file
inf.seekg(-28, ios::end); // move to the 28th byte before end of the file
```

#### C++11

auto: access by value, i is **read-only**
```c++
for (auto i : v)
```
auto: access by reference, i is **modifiable**
```c++
for (auto &i : v)
```

null pointer
```c++
nullptr
```

enum types, dangerous
```c++
enum Color {
    RED,
    BLUE
};

enum Fruit {
    BANANA,
    APPLE
};

Color a = RED;
Fruit b = BANANA;

if (a == b) // The compiler will compare a and b as integers, and find they are equal
```
enum class
```c++
enum class Color {
    RED,
    BLUE
};
enum class Fruit {
    BANANA,
    APPLE
};
 
Color a = Color::RED; // note: RED is not accessible any more, we have to use Color::RED
Fruit b = Fruit::BANANA; // note: BANANA is not accessible any more, we have to use Fruit::BANANA
```
initializer_list
```c++
vector<int> vArray[5] = {3, 2, 7, 5, 8}; // // calls constructor vector<int>(initializer_list<int>);
```

* override: if the function does not override a base class function, the compiler will return an error.
* final: restrict the user from overriding a function


### Notes in python

Tuples can be thought of as **read-only** lists, and is faster

exception
```python
assert 1 > 0 # same with c++

try:
    a = 1 + 2
    a = b
except NameError, e:
    print e
>> name 'b' is not defined
```

constructor & destructor
```python
class Point:
   def __init( self, x=0, y=0):
      self.x = x
      self.y = y
   def __del__(self):
      class_name = self.__class__.__name__
      print class_name, "destroyed"
```

inheritance and polymorphism
```python
class Animal:
   def __init__(self, name=''):
      self.name = name

   def talk(self):
      pass

class Cat(Animal):
   def talk(self):
      print "Meow!"
      
c = Cat("Missy")
c.talk()
```

special functions: overloading
```python
__add__(self, other): # +
__sub__(self, other): # -
```

data Hiding: add a double underscore prefix
```python
__secretCount = 0 # make it private
```

regular expression
 * match: a match **only at the beginning** of the string
 * search: search the first occurence

Pass by reference vs value
All parameters (arguments) in the Python language are passed by reference. It means if you change what a parameter refers to within a function, the change also reflects back in the calling function. 

```python
# Function definition is here
def changeme( mylist ):
   "This changes a passed list into this function"
   mylist.append([1,2,3,4]);
   print "Values inside the function: ", mylist # [10, 20, 30, [1, 2, 3, 4]]
   return

# Now you can call changeme function
mylist = [10,20,30];
changeme( mylist );
print "Values outside the function: ", mylist   # [10, 20, 30, [1, 2, 3, 4]]
```

The parameter mylist is local to the function changeme. Changing mylist within the function does not affect mylist. 
```python
# Function definition is here
def changeme( mylist ):
   "This changes a passed list into this function"
   mylist = [1,2,3,4]; # This would assig new reference in mylist
   print "Values inside the function: ", mylist  # [1, 2, 3, 4]
   return

# Now you can call changeme function
mylist = [10,20,30];
changeme( mylist );
print "Values outside the function: ", mylist    # [10, 20, 30]
```

```python
>>> b = []
>>> a = [1]
>>> b.append(a)
>>> a.pop()
>>> b
[[]]
```

**Funtional Programming**
* iterator
```python
>>> L = [1,2,3]
>>> it = iter(L)
>>> print it
<...iterator object at ...>
>>> it.next()
1
>>> it.next()
2
```

```python
>>> L = [1,2,3]
>>> iterator = iter(L)
>>> t = tuple(iterator)
>>> t
(1, 2, 3)
```
* Generator & List expression
```python
# Generator expression -- returns iterator
stripped_iter = (line.strip() for line in line_list)

# List comprehension -- returns list
stripped_list = [line.strip() for line in line_list]
```
* Generator: these two iterators are the same
```python
it = iter([0, 1, 2])

def generate_ints(N):
    for i in range(N):
        yield i
it = generate_ints(3)
```
* **Built-in functions: zip**
```python
x = [1, 2, 3]
y = [4, 5, 6]
zipped = zip(x, y)
print(zipped)
print(zip(*zipped))
>> [(1, 4), (2, 5), (3, 6)]
>> [(1, 2, 3), (4, 5, 6)]
```

* **Built-in functions: map**
```python
def upper(s): return s.upper()
print map(upper, ["a", "d"])
>> ['A', 'D']
# it is the same with the following
print [upper(s) for s in ['a', 'd']]
```
* **Built-in functions: filter**
```python
def is_even(x): return (x % 2) == 0
filter(is_even, range(10))
>> [0, 2, 4, 6, 8]
# it is the same with the following
[x for x in range(10) if is_even(x)]
```
* **Built-in functions: reduce**
```python
import operator
print reduce(operator.concat, ['A', 'BB', 'C']) # func(func(A, B), C)
>> 'ABBC'
```
* **lambda expression**
```python
adder = lambda x, y: x+y
>> print adder(1,2)
```


### Notes in Algorithms

```
DFS traversal
Don't confuse inorder preorder postorder
inorder(root->left);
xxxx
inorder(root->right);
```


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

Reservoir sampling: choose i from a sample randomly (n is uncertain)
Case: sample size 1: when i-th element comes, keep it with prob = 1/i, throw it with prob = 1-1/i

Topological sort

```
    Using BFS
    L: empty list that contain sorted elements
    put all the nodes that has 0-indegree to stack S
    for every node n in S:
        remove n from S
        add n to the tail of L
        for any subnode m that satisfies n->m:
            remove edge of n->m
            if node m has 0-indegree
                add it to S
    if graph has edges:
        cycle exists
    else:
        return cycle
```
 
```
    Using DFS
    
    for all n:
        if node n has not been visited:
            dfs(n)
    
    dfs(n):
        if n has been visited temporarily: return false // cycle exists
        set node n as temporary
        for m with n->m:
            dfs(m)
        set node n as permanant
        add n to the List
 ```
    
    
 

