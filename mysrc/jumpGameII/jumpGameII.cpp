// Source : https://leetcode.com/problems/jump-game-ii/
// Author : Albin Zeng
// Date : 2015-05-03

/******************************************************************************************************************************
 *
 * Given an array of non-negative integers, you are initially positioned at the first index of the array.
 *
 * Each element in the array represents your maximum jump length at that position.  *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * For example:
 * Given array A = [2,3,1,1,4]
 *
 * The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
 *
 *******************************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {

      int result = 0
      int now_last = 0;
      int pre_last = 0;

      for (int i=0; i<nums.size(); i++) {
        if (i<=pre_last) {
          now_last = now_last > i+nums[i] ? now_last : i+nums[i];
        } else {
          pre_last = now_last;
          result++;
          now_last = now_last > i+nums[i] ? now_last : i+nums[i];
        }
      }

      return result;
    }
};

int main() {
  int A[6] = {1,2,3}; // ,234,2,2,3,1,23,4,34,324,234};
  vector<int> a(A, A+3);
  cout<<(new Solution)->jump(a)<<endl;
}
