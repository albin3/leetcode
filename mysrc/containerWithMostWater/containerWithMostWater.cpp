// Source : https://leetcode.com/problems/container-with-most-water/
// Author : Albin Zeng
// Date : 2015-04-12
// Reference : http://harrifeng.github.io/algo/leetcode/container-with-most-water.html

/*****************************************************************************************************************
 *
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 *
 * Note: You may not slant the container.
 *
 ****************************************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 双指针解法
    int maxArea(vector<int> &height) {
      
      int i = 0;
      int l = height[0];
      int j = height.size()-1;
      int r = height[height.size()-1];
      int maxArea = 0;
      int tmpArea = 0;

      if (j<=i) return 0;

      maxArea = (j-i)*min(height[i], height[j]);

      while (i<j) {

        if (height[i]<height[j]) {
          while (i<j && height[i]<=l) {
            i++;
          }
          l = height[i];
        } else {
          while (i<j && height[j]<=r) {
            --j;
          }
          r = height[j];
        }

        tmpArea = (j-i)*min(height[i], height[j]); 
        if (tmpArea>maxArea) {
          maxArea = tmpArea;
        }

      }

      return maxArea;
    }

    int min(int x, int y) {

      return x<y ? x : y;

    }
};

int main(int argc, char* argv[]) {
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(4);
  v.push_back(3);
  cout<<(new Solution)->maxArea(v)<<endl;
}
