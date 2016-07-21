class Solution(object):
    # hard
    def findMedianSortedArrays(self, num1, num2):
        m = len(num1)
        n = len(num2)
        mid = (m + n) / 2
        if (m + n) % 2 == 1:
            return self.findK(num1, m, num2, n, mid + 1)
        else:
            mid1 = self.findK(num1, m, num2, n, mid)
            mid2 = self.findK(num1, m, num2, n, mid + 1)
            print mid1, mid2
            return float(mid1 + mid2) / 2
        
    def findK(self, num1, m, num2, n, k):
        if m == 0:
            return num2[k - 1]
        if n == 0:
            return num1[k - 1]
        i = m / 2
        j = n / 2
        print m, n, i, j, k
        if num1[i] <= num2[j]:
            if k > i + j + 1:
                return self.findK(num1[i + 1:], m - i - 1, num2, n, k - i - 1)
            else:
                return self.findK(num1, m, num2, j, k)
        else:
            return self.findK(num2, n, num1, m, k)
