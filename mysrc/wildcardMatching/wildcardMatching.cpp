// Source : https://leetcode.com/problems/wildcard-matching/
// Author : Albin Zeng
// Date : 2015-04-29

/****************************************************************************
 * 
 * Implement wildcard pattern matching with support for '?' and '*'.
 *
 * '?' Matches any single character.
 * '*' Matches any sequence of characters (including the empty sequence).

 * The matching should cover the entire input string (not partial).
 * 
 * The function prototype should be:
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "*") → true
 * isMatch("aa", "a*") → true
 * isMatch("ab", "?*") → true
 * isMatch("aab", "c*a*b") → false
 * 
 *****************************************************************************/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    // 检测s，用到s用完为止
    bool isMatch(string s, string p) {

      bool result=false;

      int slen = s.size();
      int plen = p.size();
      int ss=-1,sp=-1;
      int i=0,j=0;
      for (;i<s.size();) {
        // p用净而s还有
        if (j>=p.size()) {
          if (sp==-1) return false;
          else {
            ss = ss+1;
            i = ss;
            j = sp;
            continue;
          }
        }

        switch(p[j]) {
          case '*':
            ss = i;
            sp = j;
            j++;
            continue;
          case '?':
            i++;
            j++;
            continue;
          default:
            if (p[j] == s[i]) {
              i++;
              j++;
              continue;
            } else {
              if (sp==-1) return false;
              else {
                ss = ss+1;
                i = ss;
                j = sp;
                continue;
              }
            }
        }
      }

      while (p[j] == '*') j++;

      if (j == plen) result = true;
      else result = false;

      return result;
    }
};

int main() {
  cout<<(new Solution)->isMatch("aa", "a")<<endl;
  cout<<(new Solution)->isMatch("aa", "aa")<<endl;
  cout<<(new Solution)->isMatch("aaa", "aa")<<endl;
  cout<<(new Solution)->isMatch("aa", "*")<<endl;
  cout<<(new Solution)->isMatch("aa", "a*")<<endl;
  cout<<(new Solution)->isMatch("ab", "?*")<<endl;
  cout<<(new Solution)->isMatch("aab", "c*a*b")<<endl;
  cout<<(new Solution)->isMatch("", "*")<<endl;
  cout<<(new Solution)->isMatch("c", "*?*")<<endl;
  cout<<(new Solution)->isMatch("abefcdgiescdfimde", "ab*cd?i*de")<<endl;
}
