#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& A) {
        int i = 0;
        int n = A.size();
        while (i < n)
        {
        	cout << i << " new step ";
        	for (int j = 0; j < n; j++)
        		cout << A[j] << " ";
        	cout << endl;
            if (A[i] != (i+1) && A[i] >= 1 && A[i] <= n && A[A[i]-1] != A[i]) {
            	// if A[i] is not in the right direction, swap it to the right direction
                swap(A[i], A[A[i]-1]); 
            }
            else
                i++;
        }
        for (i = 0; i < n; ++i)
            if (A[i] != (i+1))
                return i+1;
        return n+1;
    }
};


int main() {
	Solution s;
	int A[] = {3, 2, 5, 0, 7, -1,6, 1, 4};
	vector<int> B(A, A + sizeof(A) / sizeof(int));
	cout << s.firstMissingPositive(B) << endl;
}
