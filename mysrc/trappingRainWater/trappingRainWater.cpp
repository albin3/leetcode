// Source : https://leetcode.com/problemset/algorithms/
// Author : Albin Zeng
// Date : 2015-04-27

/***************************************************************************************************
 *
 * Given n non-negative integers representing an elevation map where the width of each bar is 1, 
 * compute how much water it is able to trap after raining.
 *
 * For example, 
 * Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
 *
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
 * In this case, 6 units of rain water (blue section) are being trapped. 
 * Thanks Marcos for contributing this image!
 *
 **************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

      int result = 0;
      int len = height.size();

      if (len == 0) return result;

      int pos = 0;
      for (int i=0; i<len; i++) {
        if (height[i] > height[pos]) pos = i;
      }


      int leftmax = 0;
      for (int i=0; i<pos; i++) {
        if (height[i]>leftmax && pos-i-1>0) {
          int v = (pos-i-1) * (height[i]-leftmax);
          for (int j=i+1; j<pos; j++) {
            if (height[j] < height[i]) {
              v-= height[j]>leftmax ? height[j]-leftmax : 0;
            } else {
              v-= height[i]-leftmax;
            }
          }
          result += v;
          leftmax = height[i];
        }
      }

      int rightmax = 0;
      for (int i=len-1; i>pos; i--) {
        if (height[i]>rightmax && i-pos-1>0) {
          int v = (i-pos-1) * (height[i]-rightmax);
          for (int j=i-1; j>pos; j--) {
            if (height[j] < height[i]) {
              v-= height[j]>rightmax ? height[j]-rightmax : 0;
            } else {
              v-= height[i]-rightmax;
            }
          }
          result += v;
          rightmax = height[i];
        }
      }

      return result;
    }
};

int main() {
  int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  vector<int> v(a, a+12);
  cout<<(new Solution)->trap(v)<<endl;
}
