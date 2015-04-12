// Source : https://leetcode.com/problems/3sum-closest/
// Author : Albin Zeng
// Date : 2015-04-12

/*******************************************************************************************************************
 *
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
 * Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *
 *
 *  For example, given array S = {-1 2 1 -4}, and target = 1.
 *
 *  The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 *
 *
 *******************************************************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    // Same to 3Sum, two point Search.
    int threeSumClosest(vector<int> &num, int target) {
      if (num.size()<3) return target;


      // sort by algorithm.
      sort(num.begin(), num.end());

      int result = num[0]+num[1]+num[2];

      int most_close = getDistance(num[0]+num[1]+num[2], target);
      for (int i=0; i<num.size(); i++) {
        int t = target-num[i];

        // get most close to t
        int l = i+1;
        int r = num.size()-1;
        while (l<r) {
          int sum = num[l]+num[r];
          // update.
          if (getDistance(sum, t) < most_close) {
            most_close = getDistance(sum, t);
            result = sum+num[i];
          }
          if (sum==t) {
            return target;
          } else if (l<r && sum < t) {
            l++;
          } else if (l<r && sum > t) {
            r--;
          }
        }
      }

      return result;
    }

    int getDistance(int x, int y) {
      return x>y ? x-y : y-x;
    }
};

int main() {
  vector<int> v;
  v.push_back(0);
  v.push_back(2);
  v.push_back(1);
  v.push_back(-3);
  cout<<(new Solution)->threeSumClosest(v,1)<<endl;
}
