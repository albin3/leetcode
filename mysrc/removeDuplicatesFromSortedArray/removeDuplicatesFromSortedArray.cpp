// Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Author : Albin Zeng
// Date : 2015-04-14

/*******************************************************************************************************************************
 *
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 *
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 *
 *
 * For example,
 *
 * Given input array A = [1,1,2],
 *
 * Your function should return length = 2, and A is now [1,2].
 *
 *
 *******************************************************************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {

      if (n<2) return n;

      int result = 0;

      int left=1;
      int right=1;
      while (right<n) {

        if (right<n && A[right-1]!=A[right]) {
          A[left++] = A[right];
        }

        right++;
      }

      return left;
    }
};

int main() {

  int A[5] = {1,3,3,4,4};
  int n = 5;
  cout<<(new Solution)->removeDuplicates(A, n)<<endl;

  for (int i=0 ; i<n; i++) {
    cout<<A[i]<<endl;
  }

  return 0;
}
