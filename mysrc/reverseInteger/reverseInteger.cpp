// Source : https://leetcode.com/problems/reverse-integer/
// Author : Albin Zeng
// Date   : 2015-04-11

/*********************************************************************************************************************
 *
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 *
 * Example2: x = -123, return -321
 *
 * Have you thought about this?
 * Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
 *
 * If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 *
 * Did you notice that the reversed integer might overflow? 
 * Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. 
 * How should you handle such cases?
 *
 * For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 *
 * Update (2014-11-10):
 * Test cases had been added to test the overflow behavior.
 *
 ********************************************************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {

      int reverse = 0;
      int result = reverse;

      while (x!=0) {
        int d = x%10;
        x = x/10;
        reverse = reverse * 10 + d;

        // check overflow.
        if (reverse/10 == result) {
          result = reverse;
        } else {
          return 0;
        }
      }
      result = result * x;

      return reverse;
    }
};

int main(int argc, char* argv[]) {
  cout<<(new Solution)->reverse(-321)<<endl;
}
