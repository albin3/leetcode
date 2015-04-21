// Source : https://leetcode.com/problems/search-for-a-range/
// Author : Albin Zeng
// Date : 2015-04-20

/****************************************************************************************************
 * 
 * Given a sorted array of integers, find the starting and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4].
 * 
 ****************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Binary search 理解深入了
    vector<int> searchRange(int A[], int n, int target) {
      vector<int> result;

      if (n<1) {
        result.push_back(-1);
        result.push_back(-1);
        return result;
      }

      if (target < A[0] || target > A[n-1]) {
        result.push_back(-1);
        result.push_back(-1);
        return result;
      }

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
      if (A[left] == target) {
        result.push_back(left);
      } else {
        result.push_back(-1);
      }

      left = 0;
      right = n;
      while (left<right) {
        int mid = (left+right)/2;
        if (A[mid] <= target) {
          left = mid+1;
        } else {
          right = mid;
        }
      }
      if (A[left-1] == target) {
        result.push_back(left-1);
      } else {
        result.push_back(-1);
      }

      return result;
    }
};

int main() {
  int A[6] = {1,1,3};
  int n = 3, target = 2;

  vector<int> v = (new Solution)->searchRange(A,n,target);

  for (int i=0; i<v.size(); i++) {
    cout<<v[i]<<endl;
  }

  return 0;
}
