// Source : https://leetcode.com/problems/search-in-rotated-sorted-array/
// Author : Albin Zeng // Date : 2015-04-19

/**************************************************************************************
 *
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * You are given a target value to search. 
 * If found in the array return its index, otherwise return -1.
 *
 * You may assume no duplicate exists in the array.
 *
 *************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(int A[], int n, int target) {

      if (n<1) return -1;
      if (n==1) return A[0]==target ? 0 : -1;

      int result = -1;
      
      int left = 0;
      int right = n-1;
      while (left<right && A[left]>A[right]) {
        int mid = (left+right)/2;
        if(A[mid] >= A[left]) {
          left = mid+1;
        } else {
          right = mid;
        }
      }

      int pivot = left;
      left = pivot;
      right = pivot + n;
      while (left!=right) {
        int mid = (left+right)/2;
        if (A[mid%n] == target) {
          result = mid%n;
          break;
        }
        if (A[mid%n] < target) {
          left = mid+1;
        } else {
          right = mid;
        }
      }

      return result;
    }
};

int main() {
  int A[] = {1,3,5};
  cout<<(new Solution)->search(A,3,5)<<endl;
}
