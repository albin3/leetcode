// Source : https://leetcode.com/problems/search-insert-position/
// Author : Albin Zeng
// Date : 2015-04-21

/*******************************************************************************************
 * 
 * Given a sorted array and a target value, return the index if the target is found. 
 * 
 * If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 * 
 ********************************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
      int result;

      if (n<1) return 0;

      int left = 0;
      int right = n;

      while (left<right) {
        int mid = (left+right)/2;
        if (A[mid] < target) {
          left = mid+1;
        } else {
          right = mid;
        }
      
      }
      result = left;

      return result;
    }
};

int main() {
  int A[4] = {1,1,2,6};
  int n=4,target=2;
  cout<<(new Solution)->searchInsert(A,n,target)<<endl;
}
