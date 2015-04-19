// Source : https://leetcode.com/problems/longest-valid-parentheses/
// Author : Albin Zeng
// Date : 2015-04-19

/***************************************************************************************************************
 *
 * Given a string containing just the characters '(' and ')', 
 * find the length of the longest valid (well-formed) parentheses substring.
 *
 * For "(()", the longest valid parentheses substring is "()", which has length = 2.
 * 
 * Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
 *
 **************************************************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    // 思路： 从右往左找一遍，再从左往右找一遍.
    //        只有栈空的时候才记录长度
    int longestValidParentheses(string s) {

      int len = s.size();
      if (len<2) return 0;

      int result = 0;

      int left = 0;
      int stack = 0;
      int pos = -1;
      for (int i=0; i<len; i++) {

        if (s[i]=='(') {
          stack++;
        } else {
          if (stack==0) {
            pos = i;
          } else {
            stack--;
          }
        }

        if (stack == 0) {
          left = i-pos > left ? i-pos : left;
        }

      }

      int right = 0;
      stack = 0;
      pos = len;
      for (int i=len-1; i>=0; i--) {
        
        if (s[i] == ')') {
          stack++;
        } else {
          if (stack == 0) {
            pos = i;
          } else {
            stack --;
          }
        }

        if (stack==0) {
          right = pos-i > right ? pos-i : right;
        }

      }

      result = left > right ? left : right;
      cout<<left<<endl<<right<<endl;


      return result;
    }
};

int main() {
  cout<<(new Solution)->longestValidParentheses("()")<<endl;
}
