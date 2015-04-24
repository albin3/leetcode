// Source : https://leetcode.com/problems/count-and-say/
// Author : Albin Zeng
// Date : 2015-04-24

/***************************************************************************************
 * 
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 * 
 * Note: The sequence of integers will be represented as a string.
 * 
 *************************************************************************************/

#include <sstream>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
      string result = "1";

      if (n<1)  return "";
      if (n==1) return result;

      for (int i=1; i<n; i++) {
        result = nextTip(result);
      }

      return result;
    }

    string nextTip(string &str) {

      string result = "";

      if (str.size() == 0) return result;

      int pos = 0;
      char c = str[0];
      for (int i=0; i<str.size() ;i++) {
        if (c == str[i]) {
          continue;
        } else {
          int num = i-pos;
          ostringstream ss;
          ss<<num;
          result = result + ss.str() + c;

          pos = i;
          c = str[i];
        }
      }

      int num = str.size()-pos;
      ostringstream ss;
      ss<<num;
      result = result + ss.str() + c;

      return result;
    }
};

int main() {
  cout<<(new Solution)->countAndSay(5)<<endl;
}
