// Source : https://leetcode.com/problems/valid-parentheses/
// Author : Albin Zeng
// Date : 2015-04-13

/**************************************************************************************************************************
 *
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 *
 *************************************************************************************************************************/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

      bool result = false;

      stack<char> stk;

      for (int i=0; i<s.size(); i++) {

        if (s[i]=='(' || s[i]=='[' || s[i]=='{') {

          stk.push(s[i]);

        } else if (s[i]==')') {

          if (!stk.empty() && stk.top() == '(') {
            stk.pop();
          } else {
            return false;
          }

        } else if (s[i]==']') {

          if (!stk.empty() && stk.top() == '[') {
            stk.pop();
          } else {
            return false;
          }

        } else if (s[i]=='}') {

          if (!stk.empty() && stk.top() == '{') {
            stk.pop();
          } else {
            return false;
          }

        } else {
          return false;
        }
      }

      if (stk.empty()) {
        result = true;
      }

      return result;
    }
};

int main() {
  string str = "][]{}()";
  stack<int> st;
  cout<<(new Solution)->isValid(str)<<endl;
}

