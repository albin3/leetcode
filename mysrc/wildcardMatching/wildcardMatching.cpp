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
#include <vector>
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

    bool isMatch2(string s, string p) {
      bool result = false;

      vector<vector<bool> > dp;

      if (p.size()<1) return false;
      // 第一行单独处理，作为后面的参考系
      if (p[0] == '*') {
        vector<bool> tmp;
        for (int j=0; j<=s.size(); j++) {
          tmp.push_back(true);
        }
        dp.push_back(tmp);
      } else if (s.size()>0 && (p[0]=='?' || p[0]==s[0])){
        vector<bool> tmp;
        tmp.push_back(false);
        tmp.push_back(true);
        for (int j=2; j<=s.size(); j++) {
          tmp.push_back(false);
        }
        dp.push_back(tmp);
      } else {
        vector<bool> tmp;
        for (int j=0; j<=s.size(); j++) {
          tmp.push_back(false);
        }
        dp.push_back(tmp);
      }

      for (int i=1; i<p.size(); i++) {
        vector<bool> tmp;
        if (p[i] == '*') {
          for (int j=0; j<=s.size(); j++) {
            if (dp[i-1][j] || j>0 && tmp[j-1]) {
              tmp.push_back(true);
            } else {
              tmp.push_back(false);
            }
          }
          dp.push_back(tmp);
        } else if (p[i] == '?') {
          for (int j=0; j<=s.size(); j++) {
            if (j>0 && dp[i-1][j-1]) {
              tmp.push_back(true);
            } else {
              tmp.push_back(false);
            }
          }
          dp.push_back(tmp);
        } else {
          for (int j=0; j<=s.size(); j++) {
            if (j>1 && dp[i-1][j-1] && p[i] == s[j-1]) {
              tmp.push_back(true);
            } else {
              tmp.push_back(false);
            }
          }
          dp.push_back(tmp);
        }
      }

      return dp[p.size()-1][s.size()];
    }
};

int main() {
  cout<<"solution1: "<<endl;
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
  cout<<"solution2: "<<endl;
  cout<<(new Solution)->isMatch2("aa", "a")<<endl;
  cout<<(new Solution)->isMatch2("aa", "aa")<<endl;
  cout<<(new Solution)->isMatch2("aaa", "aa")<<endl;
  cout<<(new Solution)->isMatch2("aa", "*")<<endl;
  cout<<(new Solution)->isMatch2("aa", "a*")<<endl;
  cout<<(new Solution)->isMatch2("ab", "?*")<<endl;
  cout<<(new Solution)->isMatch2("aab", "c*a*b")<<endl;
  cout<<(new Solution)->isMatch2("", "*")<<endl;
  cout<<(new Solution)->isMatch2("c", "*?*")<<endl;
  cout<<(new Solution)->isMatch2("abefcdgiescdfimde", "ab*cd?i*de")<<endl;
}
