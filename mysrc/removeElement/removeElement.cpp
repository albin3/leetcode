// Source : https://leetcode.com/problems/remove-element/
// Author : Albin Zeng
// Date : 2015-04-14

/****************************************************************************************************
 *
 * Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 *
 ****************************************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
      
      int left = 0;
      int right = 0;

      while (right<n) {

        if (A[right] != elem) {
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
  int t = 3;
  cout<<(new Solution)->removeElement(A, n, t)<<endl;

  for (int i=0 ; i<n; i++) {
    cout<<A[i]<<endl;
  }

  return 0;

}

