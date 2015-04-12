// Source : https://leetcode.com/problems/longest-common-prefix/
// Author : Albin Zeng
// Date : 2015-04-12

/****************************************************************************************
 *
 * Write a function to find the longest common prefix string amongst an array of strings.
 *
 ***************************************************************************************/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {

      if (strs.size()<1) return "";

      string result = strs[0];

      for (int i=1; i<strs.size(); i++) {

        int j=0;

        for ( ;j<result.size() && j<strs[i].size(); j++) {

          if (result[j] != strs[i][j]) {
            break;
          }

        }

        result = result.substr(0, j);
      }
      
      return result;
    }
};

int main() {
  vector<string> v;
  v.push_back("aa");
  v.push_back("a");
  cout<<(new Solution)->longestCommonPrefix(v)<<endl;
}
