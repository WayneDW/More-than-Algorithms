# leetCodeOJ in C++ and Python


### Generate framework 

```python
./framework.py 19
```
Let's deal with 19_Remove_Nth_Node_From_End_of_List
```
19_Remove_Nth_Node_From_End_of_List.py generated successfully!

19_Remove_Nth_Node_From_End_of_List.cpp generated successfully!
```
If some file already existed, do nothing in that file
```python
./framework.py 19
```

```
Let's deal with 19_Remove_Nth_Node_From_End_of_List

19_Remove_Nth_Node_From_End_of_List.py already existed!
```

### Upload script

Type in the question number and the commit words as the rest of the parameters
```
./upload.sh 19 Linked List double pointer
```

### Notes in C++

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

```c++
vector<int> v = {0, 1, 2, 3, 4, 5};
for (auto i : v) // access by value, the type of i is int
for (auto&& i : v) // access by reference, the type of i is int&
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
string.substr(2) # abcdefg -> cde

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
int dat[] = {0, 1};
vector<int> vec(dat, dat + sizeof(dat) / sizeof(int));
```
Vector operation, random access, constant insertion at the end, o(n) otherwise
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

```c++
istringstream // convert ostringstream to a set of variables
istringstream s(string); // to initialize
int val; // or other types
s >> val; // set value
if (! (s >> val)) // to determine if it has reached the end

ostringstream // convert output (analogy) to string
see example c++ 165, 297
```
```c++
stoi // convert string to int
```

```c++
nullptr // null pointer in C++11
```

### Notes in Algorithms

```
Master Theorem

T(n) = aT(n/b) + n^c
denote d = log(a) / log(b)
then time complexity is as follows
// intuitive thinking: when d = c, the problem has log(n) layers with n^c complexity in each
i,   c = d --> o(n^d * log(n))  
ii,  c < d --> o(n^d)
iii, c > d --> o(n^c)
```

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
#### Generators
Generators are iterators, but you can only iterate over them once. It's because they do not store all the values in memory, they generate the values on the fly:
```python
>>> mygenerator = (x*x for x in range(3))
>>> for i in mygenerator:
...    print(i)
0
1
4
```

#### Yield

Yield is a keyword that is used like return, except the function will return a generator.
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


