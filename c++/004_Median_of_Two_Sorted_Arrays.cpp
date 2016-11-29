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

    /* Convert to find the Kth element in two sorted arrays: A and B
     *  a) If odd, just return the Kth element
     *  b) If even, return average of Kth + (K+1)th element 
     * 
     * How to find Kth element:
     * For K == 1, return min(A[0], B[0]);
     * For A == NULL, return B[K-1]; 
     * For B == NULL, return A[K-1]; 
     * Drop the K/2 elements for each time, untile K == 1 or (A == NULL or B == NULL);
     *      If A[K/2] < B[K/2], remove elements A[0..K/2] from A, then search (K-K/2)th from the remaining A and B
     *                    else, remove elements B[0..K/2] from B, then search (K-K/2)th from the remaining A and B 
     * 
     *      one condition, there is no K/2 elements in either array (A or B), but there must more that K/2 in other array!
     *      Just drop K/2 elements in another array directly.
     *      How to: Assign max value, so above euqation can still work. Eg, (INT_MAX < B[K/2] == false) will drop K/2 from B;
     */
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m+n == 0) return 0;
        
        if ( (m+n) % 2 == 0 ) {
            return double(findKth(nums1, 0, nums2, 0, (m+n)/2) + findKth(nums1, 0, nums2, 0, (m+n)/2+1))/2;
        } else {
            return double(findKth(nums1, 0, nums2, 0, (m+n+1)/2));
        }
    }
    
    int findKth(vector<int>& A, int a_start, vector<int> & B, int b_start, int k) {
        if (a_start >= A.size()) {
            return B[b_start + k - 1];
        }
        if (b_start >= B.size()) {
            return A[a_start + k - 1];
        }
        if (k == 1) {
            return min(A[a_start], B[b_start]);
        }
        
        //INT_MAX: drop emelemts from other array
        int a_mid_value = a_start + k/2 -1 < int(A.size() ) ? A[a_start + k/2 -1] : INT_MAX; 
        int b_mid_value = b_start + k/2 -1 < int(B.size() ) ? B[b_start + k/2 -1] : INT_MAX;
        if (a_mid_value < b_mid_value) {
            return findKth(A, a_start + k/2, B, b_start, k - k/2);
        } else {
            return findKth(A, a_start, B, b_start + k/2, k - k/2);
        }
        
    }