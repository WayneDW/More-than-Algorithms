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

To avoid overflow
```c++
p = (unsigned long long) p * m / n ...
```

```
vector<int> vec(10, 1); // initialize 10 number of 1
```

```cpp
// string
string.substr(2, 2) # abcdefg -> cd
string.substr(2) # abcdefg -> cde

string.push_back('a');
string.append("abc");
```
```c
queue<TreeNode*> rather than queue<TreeNode>
```


```c++
/* Vector operation */
// simple way to initialization
int dat[] = {0, 1};
vector<int> vec(dat, dat + sizeof(dat) / sizeof(int));

vec.erase(vec.begin() + 1); // delete the 2nd element
vec.erase(vec.end() - 1); // erase the last element
vec.erase(vec.begin(), vec.begin() + 2); // delete the first 2 elements
vec.insert(vec.begin(), tmp); // insert value at the beginning

for (int i = 0; i < vec.size(); i++)  # wrong way if we do vector operations in the loop

int len = vec.size();
for (int i = 0; i < len; i++)
    ***
```

### Notes in python

```python
b = []
a = [1]
b.append(a)
a.pop()
```
```
print b
[[]]
```


