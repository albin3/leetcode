// Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author : Albin Zeng
// Date : 2015-04-12

/************************************************************************************************************
 *
 * Given a digit string, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 *
 *
 * Input:Digit string "23"
 * 
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 * Note:
 *
 * Although the above answer is in lexicographical order, your answer could be in any order you want.
 *
 ************************************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {

      vector<string> result;

      if (digits.size() <1) return result;

      vector<vector<string> > v;
      vector<string> tmp;
      tmp.push_back("a"); tmp.push_back("b"); tmp.push_back("c"); v.push_back(tmp);
      tmp.clear();
      tmp.push_back("d"); tmp.push_back("e"); tmp.push_back("f"); v.push_back(tmp);
      tmp.clear();
      tmp.push_back("g"); tmp.push_back("h"); tmp.push_back("i"); v.push_back(tmp);
      tmp.clear();
      tmp.push_back("j"); tmp.push_back("k"); tmp.push_back("l"); v.push_back(tmp);
      tmp.clear();
      tmp.push_back("m"); tmp.push_back("n"); tmp.push_back("o"); v.push_back(tmp);
      tmp.clear();
      tmp.push_back("p"); tmp.push_back("q"); tmp.push_back("r"); tmp.push_back("s"); v.push_back(tmp);
      tmp.clear();
      tmp.push_back("t"); tmp.push_back("u"); tmp.push_back("v"); v.push_back(tmp);
      tmp.clear();
      tmp.push_back("w"); tmp.push_back("x"); tmp.push_back("y"); tmp.push_back("z"); v.push_back(tmp);

      result = v[digits[0]-'2'];
      for (int i=1; i<digits.size(); i++) {
        int idx = digits[i]-'2';

        vector<string> mid;
        for (int j=0; j<v[idx].size(); j++) {
          for (int k=0; k<result.size(); k++) {
            mid.push_back(result[k]+v[idx][j]);
          }
        }
        result = mid;
      }

      return result;
    }
};

int main() {
  string s = "23";
  vector<string> v = (new Solution)->letterCombinations(s);
  for (int i=0; i<v.size(); i++) {
    cout<<v[i]<<endl;
  }
}
