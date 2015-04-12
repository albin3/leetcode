// Source : https://leetcode.com/problems/roman-to-integer/
// Author : Albin Zeng
// Date : 2015-04-12

/********************************************************************************** 
* 
* Given a roman numeral, convert it to an integer.
*
* Input is guaranteed to be within the range from 1 to 3999.
* 
**********************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    // 贪心算法
    int romanToInt(string s) {

      string symbol[] =   {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};    
      int value[]     =   {1000,900,500,400, 100, 90,  50, 40,  10, 9,   5,  4,   1}; 
      int strlen[]    =   {   1,   2,  1,  2,   1,  2,  1,   2,  1,   2,  1,   2,  1};
      int len = sizeof(symbol)/sizeof(string);

      int result = 0;
      int pos = 0;
      for (int i=0; i<len; i++) {
        while (s.find(symbol[i])==pos) {
          result += value[i];
          pos += strlen[i];
        }
      }

      return result;
    }
};

int main() {
  string str = "DCCXII";
  cout<<(new Solution)->romanToInt(str)<<endl;
}
