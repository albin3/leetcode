// Source : https://leetcode.com/problems/divide-two-integers/
// Author : Albin Zeng
// Date : 2015-04-14

/***********************************************************************************
 *
 * Divide two integers without using multiplication, division and mod operator.
 *
 * If it is overflow, return MAX_INT.
 *
 ***********************************************************************************/

#include <iostream>
#include <limits>
using namespace std;

class Solution {
public:
    // TODO: 重新来一遍
    int divide(int dividend, int divisor) {

      int max = numeric_limits<int>::max();
      int min = numeric_limits<int>::min();
      if (divisor == 0) return max;

      unsigned int divid;
      unsigned int divis;
      unsigned int b = 0; // 除数
      unsigned int c = 0; // 余数

      int flag = 1;
      if (dividend<0) {
        flag = 0-flag;
        divid = (unsigned int)(-dividend);
      } else {
        divid = dividend;
      }
      if (divisor<0) {
        flag = 0-flag;
        divis = (unsigned int)(-divisor);
      } else {
        divis = divisor;
      }

      if (divisor == 1) {
        return dividend;
      }

      if (divid<divis) {
        return 0;
      } else if (divid == divis) {
        return flag > 0 ? 1 : -1;
      } 

      unsigned int mid = divis;
      int shift = 0;

       while (true) {
        if (divid>>shift < divis) {
          shift = shift -1;
          b += 1<<shift;
          divid -= divis<<shift;
          if (divid<divis) {
            c = divid;
            break;
          }
          shift = 0;
        } else if (divid>>shift == divis) {
          b += 1<<shift;
          divid -= divis<<shift;
          if (divid<divis) {
            c = divid;
            break;
          }
          shift = 0;
        }
        shift++;
      };

      if (flag>0 && b>=max) {
        return max;
      } else if (flag<0 && 0-b<=min) {
        return min;
      }

      if (flag<0) {
        return 0-b;
      } else {
        return b;
      }
    }
};

int main() {
  cout<<(new Solution)->divide(-2147483648,2)<<endl;
}
