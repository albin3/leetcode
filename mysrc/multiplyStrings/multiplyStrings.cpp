// Source : https://leetcode.com/problems/multiply-strings/
// Author : Albin Zeng
// Date : 04-29

/*********************************************************************************************
 *
 * Given two numbers represented as strings, return multiplication of the numbers as a string.
 *
 * Note: The numbers can be arbitrarily large and are non-negative.
 *
 *********************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {

      string result = "";
      string tmp = "";

      if (num1.size()<1 || num2.size()<1) return "";

      int flag = 1;
      if (num1[0] == '+' || num1[0] == '-') {
        if (num1[0] == '-') flag = flag*-1;
        num1 = num1.substr(1,num1.size()-1);
      }
      if (num2[0] == '+' || num2[0] == '-') {
        if (num2[0] == '-') flag = flag*-1;
        num2 = num2.substr(1,num2.size()-1);
      }

      int len1 = num1.size();
      int len2 = num2.size();
      int i=0;
      int carry=0;

      while (i<=len1-1+len2-1) {
        
        int n = 0;
        for (int j=0; j<len1; j++) {

          if (i-j<0 || i-j>=len2) continue;

          n += (num1[len1-1-j]-'0') * (num2[len2-1-(i-j)]-'0');
        }

        n = n+carry;

        carry = n/10;

        n = n%10 + '0';

        result = tmp + (char)n + result;

        i++;
      }

      while (carry > 0) {

        result = tmp + (char)(carry%10+'0') + result;

        carry /= 10;
      }

      int mv = 0;
      while (result[mv] == '0') mv++;

      if (mv == result.size()) return "0";

      if (mv > 0) result = result.substr(mv, result.size()-mv);

      if (flag==-1) {
        result = tmp + "-" + result;
      }

      return result;
    }
};

int main() {
  cout<<(new Solution)->multiply("92", "0")<<endl;
}
