// Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// Author : Albin Zeng
// Date   : 2015-04-10

/***************************************************************************************************
 * 
 * There are two sorted arrays A and B of size m and n respectively. 
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 *
 ***************************************************************************************************/
#include <iostream>
using namespace std;

class Solution {
public:
    // O(n) solution: merge two array and return medain.
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int* p = new int[m+n];
        int i=0;
        int j=0;
        int k=0;
        while (i<m && j<n) {
          if (A[i]<B[j]) {
            p[k++] = A[i++];
          } else {
            p[k++] = B[j++];
          }
        }
        while (i<m) {
          p[k++] = A[i++];
        }
        while (j<n) {
          p[k++] = B[j++];
        }
        int result;
        if ((m+n)%2 == 1) {
          result = p[(m+n)/2];
        } else {
          result = (p[(m+n)/2]+p[(m+n)/2-1])/2;
        }
        return result;
    }

    // O(log(m+n)) solution
    /**
     * binary search pos in A, keep numbers left pos in A is less than median.
     * than return result.
     */
    double findMedianSortedArrays1(int A[], int m, int B[], int n) {
      if (m>n) {
        return findMedianSortedArrays1(B,n,A,m);
      }

      int half = (m+n)/2;
      int l = 0;
      int r = m;
      int pos=(l+r)/2;

      if (A[m-1]<=B[0]){
        if (m==n) {
          return (A[m-1]+B[0])*1.0/2;
        } else {
          return (m+n)%2==1 ? B[(m+n)/2-m] : (B[(m+n)/2-m-1]+B[(m+n)/2-m])*1.0/2;
        }
      } else if (B[n-1]<=A[0]) {
        if (m==n) {
          return (A[0]+B[n-1])*1.0/2;
        } else {
          return (m+n)%2==1 ? B[(m+n)/2] : (B[(m+n)/2-1]+B[(m+n)/2])*1.0/2;
        }
      }

      // loop until find mid point.
      while (l!=r && ((A[pos]<B[half-pos-1]) || (A[pos]>B[half-pos]))) {

        // median is in A[pos...m-1]
        if (A[pos]<B[half-pos-1]) {
          l = pos+1;
          pos = (l+r)/2;
          
        // median is in A[pos...m-1]
        } else if (A[pos]>B[half-pos]) {
          r = pos;
          pos = (l+r)/2;
        }
      }
      // find pos split A into [0..pos-1] and [pos..m-1] ; B into [0..half-pos-1] and [half-pos..n-1]
      // result is based on (m+n)%2==1
      if ((m+n)%2==1) {
        if (pos==m) return B[half-pos];

        if (B[half-pos]<A[pos]) {
          return B[half-pos];
        } else {
          return A[pos];
        }
      } else {
        int left_median;
        int right_median; 
        if (pos==0) {
          left_median = B[half-pos-1];
        } else if (half-pos-1<0 || half-pos-1>=n){
          left_median = A[pos-1];
        } else {
          left_median = A[pos-1]>B[half-pos-1] ? A[pos-1] : B[half-pos-1];
        }
        if (pos==m) {
          right_median = B[half-pos];
        } else if (half-pos<0 || half-pos>=n){
          right_median = A[pos];
        } else {
          right_median = A[pos]<=B[half-pos] ? A[pos] : B[half-pos];
        }
        return (left_median+right_median)*1.0/2;
      }
    }
};

int main(int argc, char* argv[]) {
  int A[1] = {10};
  int B[1] = {11};
  cout<<(new Solution)->findMedianSortedArrays1(A,1,B,1)<<endl;
  return 0;
}
