// Source: https://leetcode.com/problems/rotate-image/
// Author: Albin Zeng
// Date: 2015-05-20

/*************************************************************
 *
 * You are given an n x n 2D matrix representing an image.
 *
 * Rotate the image by 90 degrees (clockwise).
 *
 * Follow up:
 * Could you do this in-place?
 *
 *************************************************************/

#include <iostream>
#include <vector>

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

      int len = matrix.size();

      for (int i=0; i<(len+1)/2; i++) {

        for (int j=0; j<len/2; j++) {

          int t = matrix[i][j]; //i,j       j,len-1-i       len-1-i, len-1-j,    len-1-j, i

          matrix[i][j] = matrix[len-1-j][i];

          matrix[len-1-j][i] = matrix[len-1-i][len-1-j];

          matrix[len-1-i][len-1-j] = matrix[j][len-1-i];

          matrix[j][len-1-i] = t;

        }

      }   

    }
};

int main() {
  ;
}
