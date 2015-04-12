// Source : https://leetcode.com/problems/integer-to-roman/
// Author : Albin Zeng
// Date   : 2015-04-12

/**
 *
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 *   1   5   10   50  100  500 1000
 *   I   V    X    L    C    D    M
 */

#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
      string result = "";

      while (num>=1000) {
        result += "M";
        num -= 1000;
      }

      if (num>=900) {
        result += "CM";
        num -= 900;
      } else if (num>=500) {
        result += "D";
        num -= 500;
        while (num>=100) {
          result += "C";
          num -= 100;
        }
      } else if (num>=400) {
        result += "CD";
        num -= 400;
      } else if (num>=100) {
        while (num>=100) {
          result += "C";
          num -= 100;
        }
      }

      if (num>=90) {
        result += "XC";
        num -= 90;
      } else if (num>=50) {
        result += "L";
        num -= 50;
        while (num>=10) {
          result += "X";
          num -= 10;
        }
      } else if (num>=40) {
        result += "XL";
        num -= 40;
      } else if (num>=10) {
        while (num>=10) {
          result += "X";
          num -= 10;
        }
      }

      if (num>=9) {
        result += "IX";
        num -= 9;
      } else if (num>=5) {
        result += "V";
        num -= 5;
        while (num>=1) {
          result += "I";
          num -= 1;
        }
      } else if (num>=4) {
        result += "IV";
        num -= 4;
      } else if (num>=1) {
        while (num>=1) {
          result += "I";
          num -= 1;
        }
      }

      return result;
    }
};

int main(int argc, char* argv[]) {
  cout<<(new Solution)->intToRoman(90)<<endl;
}
