// Source : https://leetcode.com/problems/string-to-integer-atoi/
// Author : Albin Zeng
// Date   : 2015-04-11

/*******************************************************************************************************
 *
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. 
 * If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
 * You are responsible to gather all the input requirements up front.
 *
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. 
 * If you still see your function signature accepts a const char * argument, 
 * please click the reload button  to reset your code definition.
 *
 ********************************************************************************************************
 *
 * Requirements for atoi:
 * The function first discards as many whitespace characters as necessary until the first non-whitespace 
 * character is found. Then, starting from this character, takes an optional initial plus or minus sign 
 * followed by as many numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the integral number, which 
 * are ignored and have no effect on the behavior of this function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid integral number, 
 * or if no such sequence exists because either str is empty or it contains only whitespace 
 * characters, no conversion is performed.
 *
 * If no valid conversion could be performed, a zero value is returned. 
 * If the correct value is out of the range of representable values, 
 * INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 *
 ********************************************************************************************************/

#include <iostream>
using namespace std;


class Solution {
public:
    int atoi(string str) {

      int int_max = 2147483647;
      int int_min = -2147483648;

      while (str[0]==' ') {
        str = str.substr(1,str.length()-1);
      }

      int result = 0;
      int symbol = 1;
      if (str.length()<1) return 0;
      if (str[0]=='+') {
        symbol = 1;
        str = str.substr(1,str.length()-1);
      } else if (str[0]=='-') {
        symbol = -1;
        str = str.substr(1,str.length()-1);
      }
      
      int scale = 1;
      while (str.length()>0 && str[0]>='0'&&str[0]<='9') {
        int d = str[0]-'0';
        if (scale>10) {
          if (symbol == 1) return int_max;
          else return int_min;
        } else if (scale==10) {
          if (result>214748364) {
            if (symbol == 1) return int_max;
            else return int_min;
          } else if (result==214748364) {
            if (symbol == 1) {
              if (d>7)
                return int_max;
            } else {
              if (d>8)
                return int_min;
            }
          }
        }
        result = result*10 +d;
        scale = scale + 1;
        str = str.substr(1,str.length()-1);
      }

      return result*symbol;
    }
};

int main(int argc, char* argv[]) {
  cout<<(new Solution)->atoi("2147483648")<<endl;
}
