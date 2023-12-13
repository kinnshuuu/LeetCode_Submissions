import sys

class Solution(object):
    def findMedianSortedArrays(self, a, b):
        
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        INT_MIN = -float('inf')
        INT_MAX = float('inf')
        n = len(a)
        m = len(b)
        t = n+m
        if(n>m):
            return Solution().findMedianSortedArrays(b,a)
        
        if(n == 0):
            if(m%2 == 0):
                return float(b[m/2] + b[m/2 - 1])/2
            else:
                return float(b[m/2])
        low = 0
        high = n
        left = (n + m+ 1)//2
        while(low<=high):
            mid1 = (low+high)//2
            mid2 = left - mid1
            l1 = INT_MIN
            l2 = INT_MIN
            r1 = INT_MAX
            r2 = INT_MAX
            if(mid1 < n):
                r1 = a[mid1]
            if(mid2 < m):
                r2 = b[mid2]
            if(mid1 - 1 >= 0):
                l1 = a[mid1 - 1]
            if(mid2 - 1 >= 0):
                l2 = b[mid2 - 1]
            if(l1 <= r2 and l2<=r1):
                if(t%2 == 1): return max(l1,l2)
                # print(max(l1,l2) , min(r1,r2))
                return float(max(l1,l2)+min(r1,r2))/2
            elif (l1 > r2):
                high = mid1 - 1
            else: 
                low = mid1 + 1
        