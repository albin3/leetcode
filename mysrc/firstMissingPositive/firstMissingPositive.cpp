// Source : https://leetcode.com/problemset/algorithms/
// Author : Albin Zeng
// Date : 2015-04-27

/*******************************************************************************
 * 
 * Given an unsorted integer array, find the first missing positive integer.
 *
 * For example,
 * Given [1,2,0] return 3,
 * and [3,4,-1,1] return 2.
 *
 * Your algorithm should run in O(n) time and uses constant space.
 *
 ******************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
      int len = nums.size();

      for (int i=0; i<len; i++) {
        int val=nums[i];
        if (val <= 0) continue;
        while (val-1<len && val-1>=0 && nums[val-1]!=val) {
          int tmp = nums[val-1];
          nums[val-1] = val;
          val = tmp;
        }
      }

      for (int i=0; i<len; i++) {
        if (nums[i]!=i+1) return i+1;
      }
      return len+1;
    }
};

int main() {
  ;
}
