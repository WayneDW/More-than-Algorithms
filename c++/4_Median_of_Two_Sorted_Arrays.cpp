/*
class Solution {
public:
    double findMedianSortedArrays(vector<int> A, vector<int> B) {
        int m = A.size();
        int n = B.size();
        int *tag1, *tag2;
        int tmp1 = 0, tmp2 = 0;
        tag1 = &tmp1;
        tag2 = &tmp2;
        int mid = (m + n) / 2;
        if ((m + n) % 2 == 1)
            return findK(A, m, B, n, mid + 1, tag1, tag2);
        else {
            int mid1 = findK(A, m, B, n, mid, tag1, tag2);
            int mid2 = findK(A, m, B, n, mid + 1, tag1, tag2);
            return float(mid1 + mid2) / 2;
        }
    }
    
    int findK(vector<int> A, int m, vector<int> B, int n, int k, int *tag1, int *tag2) {
        
        if (m == 0)
            return B[k - 1 + *tag2];
        else if (n == 0)
            return A[k - 1 + *tag1];
        else {
            int i = m / 2;
            int j = n / 2;
            if (A[i + *tag1] < B[j + *tag2]) {
                if (k > i + j + 1) {
                    *tag1 += i + 1;
                    return findK(A, m - i - 1, B, n, k - i - 1, tag1, tag2);
                }
                else
                    return findK(A, m, B, j, k, tag1, tag2);
            }
            else
                return findK(B, n, A, m, k, tag2, tag1);
        }
        
    }
};*/


class Solution {
public:
    int findKth(vector<int> a, int m, vector<int> b, int n, int k)
    {
        int lena = a.size() - m;
        int lenb = b.size() - n;
        if(lena > lenb)
            return findKth(b, n, a, m, k);
        if(lena == 0)
            return b[n+k-1];
        if(k == 1)
            return min(a[m], b[n]);
        int pa = min(k/2, lena);
        int pb = k - pa;
        int ida = m + pa - 1;
        int idb = n + pb - 1;
        if(a[ida] < b[idb])
            return findKth(a, m+pa, b, n, k-pa);
        else if(a[ida] > b[idb])
            return findKth(a, m, b, n+pb, k-pb);
        return a[ida];
    }
    double findMedianSortedArrays(vector<int>& a, vector<int>& b)
    {
        int t = a.size() + b.size();
        if(t % 2 == 1)
            return findKth(a, 0, b, 0, t/2+1);
        else
            return 0.5*(findKth(a, 0, b, 0, t/2) + findKth(a, 0, b, 0, t/2+1));
    }
};