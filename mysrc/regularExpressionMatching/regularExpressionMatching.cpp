// Source : https://leetcode.com/problems/regular-expression-matching/
// Author : Albin Zeng
// Date : 2015-04-12

/*****************************************************************************************************
 * 
 * Implement regular expression matching with support for '.' and '*'.
 * 
 *   '.' Matches any single character.
 *   
 *   '*' Matches zero or more of the preceding element.
 *
 *   The matching should cover the entire input string (not partial).
 *
 *   The function prototype should be:
 *   bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 * 
 **************************************************************************************************/

#include <iostream>
using namespace std;

class Solution {
public:

    // 分治法解
    bool isMatch(const char *s, const char *p) {

      // handle smallest resolve.
      if (*p=='\0' && *s=='\0'){
        return true;
      } else if (*p=='\0') {
          return false;
      }

      bool result = false;

      // case 1
      if (*p=='.' && *(p+1)!='*') {
        if (*s != '\0') {
          result = result || isMatch(s+1, p+1);
        } else {
          return false;
        }
      // case 2
      } else if (*p=='.' && *(p+1)=='*') {
        int i=0;
        for (; s[i]!='\0'; i++) {
          result = result || isMatch(s+i, p+2);
        }
        result = result || isMatch(s+i, p+2);
      // case 3
      } else if (*p!='.' && *(p+1)!='*') {
        if (*p==*s) {
          result = result || isMatch(s+1, p+1);
        } else {
          return false;
        }
      // case 4
      } else if (*p!='.' && *(p+1)=='*') {
        int i=0;
        for (; s[i]==*p; i++) {
          result = result || isMatch(s+i, p+2);
        }
        result = result || isMatch(s+i, p+2);
      }

      return result;
    }

};

int main(int argc, char* argv[]) {
  cout<<endl<<"1结果："<<(new Solution)->isMatch("b", "")<<endl;
  cout<<endl<<"2结果："<<(new Solution)->isMatch("aa", "aa")<<endl;
  cout<<endl<<"3结果："<<(new Solution)->isMatch("aaa", "aa")<<endl;
  cout<<endl<<"4结果："<<(new Solution)->isMatch("aa", "a*")<<endl;
  cout<<endl<<"5结果："<<(new Solution)->isMatch("aa", ".*")<<endl;
  cout<<endl<<"6结果："<<(new Solution)->isMatch("ab", ".*")<<endl;
  cout<<endl<<"7结果："<<(new Solution)->isMatch("aab", "c*a*b")<<endl;
  cout<<endl<<"8结果："<<(new Solution)->isMatch("aaa", ".*")<<endl;
}
