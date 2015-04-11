// Source : https://leetcode.com/problems/zigzag-conversion/
// Author : Albin Zeng
// Date   : 2015-04-11

/**************************************************************************************************
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
 * (you may want to display this pattern in a fixed font for better legibility)
 *
 *     P   A   H   N
 *     A P L S I I G
 *     Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 * 
 * Write the code that will take a string and make this conversion given a number of rows:
 * 
 *     string convert(string text, int nRows);
 * 
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
 *************************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string convert(string s, int nRows) {
      int len = s.length();
      if (nRows<2) return s;
      int n = nRows + nRows-2;
      string result = s;
      int k = 0;
      for (int i=0; i<nRows; i++) {
        int j = 0;
        while (true) {
          if (j*n+i<len) {
            result[k++] = s[j*n+i];
          } else {
            break;
          }
          if (i!=0&&i!=nRows-1) {
            if(j*n+nRows+nRows-2-i<len) {
              result[k++] = s[j*n+nRows+nRows-2-i];
            } else {
              break;
            }
          }
          j++;
        }
      }
      return result;
    }
};

int main(int argc, char* argv[]) {
  string s = "ABC";
  cout<<(new Solution)->convert(s,2)<<endl;
}
