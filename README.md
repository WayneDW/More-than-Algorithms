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


### Notes in C++

To avoid overflow
```c++
p = (unsigned long long) p ...
```

```
vector<int> vec(10, 1); // initialize 10 number of 1
```

```cpp
string.substr(2, 2) # abcdefg -> cd
string.substr(2) # abcdefg -> cde
```
```c
queue<TreeNode*> rather than queue<TreeNode>
```

```c
for (int i = 0; i < vec.size(); i++)  # wrong way if we do vector operations in the loop

int len = vec.size();
for (int i = 0; i < len; i++)
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


