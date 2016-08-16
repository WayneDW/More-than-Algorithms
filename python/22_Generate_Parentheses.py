#!/usr/bin/python
import sys
import os


'''
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> allComb;
        string comb;
        findParenthesis(n, 0, 0, comb, allComb);
        return allComb;
    }
    
    void findParenthesis(int n, int nleft, int nright, string &comb, vector<string> &allComb) {
        if(nleft==n && nright==n) {
            allComb.push_back(comb);
            return;
        }
        
        if(nleft<n) {
            comb.push_back('(');
            findParenthesis(n, nleft+1, nright, comb, allComb);
            comb.pop_back();
        }
        
        if(nright<nleft) {
            comb.push_back(')');
            findParenthesis(n, nleft, nright+1, comb, allComb);
            comb.pop_back();
        }
    }
};
'''

class Solution(object):
    def generateParenthesis(self, n):
        allComb = []
        comb = ""
        self.backTracking(n, 0, 0, comb, allComb)
        return allComb
    
    def backTracking(self, n, left, right, comb, allComb):
    	print allComb
    	if n == left and n == right:
    		allComb.append(comb)
    	if left < n:
    		self.backTracking(n, left + 1, right, comb + "(", allComb)

    	if right < left:
    		self.backTracking(n, left, right + 1, comb + ")", allComb)
    	
    

def main():
    s = Solution()
    print s.generateParenthesis(3)

if __name__ == "__main__":
    main()
