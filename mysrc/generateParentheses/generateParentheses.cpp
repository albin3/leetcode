// Source : https://leetcode.com/problems/generate-parentheses/
// Author : Albin Zeng
// Date : 2015-04-13

/***********************************************************************************************************
 *
 * Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
 * 
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 *
 **********************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    // 利用了卡特兰数
    vector<string> generateParenthesis(int n) {
      
      vector<string> vs;

      if (n == 0) return vs;

      generate(n,n,"",vs);

      return vs;
    }

    // 通过动态规划的方法,找到所有解.  递归，每次添加一个字符，
    // 使添加的符合条件(l表示剩余的左括号数，r表示剩余的有括号数)： r>l, l>0
    void generate(int l, int r, string s, vector<string> &v) {

      // 左右括号放置完毕
      if (l==0 && r==0) {
        v.push_back(s);
      }

      if (l>0) {
        string str = s+"(";
        generate(l-1, r, str, v);
      } 

      if (r>l) {
        string str = s+")";
        generate(l, r-1, str, v);
      }
    }
};

int main() {
  vector<string> v;
  v = (new Solution)->generateParenthesis(2);

  for (int i=0; i<v.size(); i++) {
    cout<<v[i]<<endl;
  }
  return 0;
}
