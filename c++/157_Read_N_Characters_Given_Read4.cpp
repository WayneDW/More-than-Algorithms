#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <climits>
#include "func.cpp"

using namespace std;

/*Read N Characters Given Read4
The API: int read4(char *buf) reads 4 characters at a time from a file.
The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
Note:
The read function will only be called once for each test case.*/

// From bangbingsyb.blogspot.com/2014/11/leetcode-read-n-characters-given-read4.html

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    int read(char *buf, int n) {
        int len = 0;
        int m;
        while (len + 4 < n) {
            m = read4(but + len);
            len += m;
            if (m < 4) break; 
        }

        char last[5];
        int leftNum = min(read4(last), 4);
        for (int i = 0; i < leftNum; i++)
            buf[i + len] = last[i];   //????? weird solution
        return len;
    }
};

// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    int read(char *buf, int n) {
        int res = 0, len = n / 4 + 1;
        while (len--) res += read4(buf + res);
        return min(res, n);
    }
};


int main() {
	Solution s;
    Examples eg;
}
