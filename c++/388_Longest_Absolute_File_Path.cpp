#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>
#include <climits>
#include "000_basic.cpp"

using namespace std;

/*The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext*/

class Solution {
public:
    int lengthLongestPath(string input) {

        vector<int> layers(300);
        int maxL = 0, flen = input.size();
        for (int i = 0; i < flen; i++) {
            int cnt = 0, layer = 1, isFile = false;
            while (input[i] == '\t') {
                layer++;
                i++;
            }
            while (input[i] != '\n' && i < flen) {
                if (input[i] == '.') isFile = true;
                cnt++; i++;
            }
            if (isFile) maxL = max(maxL, layers[layer-1] + cnt);
            else layers[layer] = layers[layer-1] + cnt + 1;
        }
        return maxL;
    }
};


int main() {
	Solution s;
    Examples eg;
    cout << s.lengthLongestPath("abc") << endl;
}
