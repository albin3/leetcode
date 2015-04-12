// Source : https://leetcode.com/problems/palindrome-number/
// Author : Albin Zeng
// Date   : 2015-04-12

/***********************************************************************************************************
 * 
 * Determine whether an integer is a palindrome. Do this without extra space.
 *
 * Some hints:
 * Could negative integers be palindromes? (ie, -1)
 *
 * If you are thinking of converting the integer to string, note the restriction of using extra space.
 *
 * You could also try reversing an integer. 
 * However, if you have solved the problem "Reverse Integer", 
 * you know that the reversed integer might overflow. How would you handle such case?
 *
 * There is a more generic way of solving this problem.
 *
 **********************************************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:
    // ex:  | a|b | 分为a部分和b部分
    //      1234321 ==>  sum1 = b+d; sum2 = a+b; sum1==sum2, 则返回true
    bool isPalindrome(int x) {
      if (x<0) return false;
      if (x==0) return true;

      int scale = 0;
      int scale_tmp = 1;
      while (x/scale_tmp>=10) {
        scale++;
        scale_tmp *= 10;
      }
      scale = scale + 1;

      int scale_half = scale/2;
      int scale_half_num = 1;
      for (int i=0; i<scale_half; i++) {
        scale_half_num *= 10;
      }

      // 数的后半部分自己和自己求和
      int sum1 = 0;
      for (int i=0; i<scale_half; i++) {
        sum1 = sum1*10 + getNNum(x,i) + getNNum(x,scale_half-1-i);
      }
      // 数的前半部分加上后半部分
      int sum2 = 0;
      if (scale%2 == 1) {
        sum2 = x/(scale_half_num*10) + x%scale_half_num;
      } else {
        sum2 = x/scale_half_num + x%scale_half_num;
      }

      if (sum1==sum2) {
        return true;
      } else {
        return false;
      }
    }

    // 返回数字第n位的数
    int getNNum(int x, int n) {
      for (int i=0; i<n; i++) {
        x = x/10;
      }
      return x%10;
    }
};

int main(int argc, char* argv[]) {
  cout<<(new Solution)->isPalindrome(1410110141)<<endl;
}
