// Source : 
// Author : Albin Zeng
// Date : 2015-04-14

/********************************************************************************************************************************************
 *
 * Implement strStr().
 *
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 *
 * Update (2014-11-02):
 * 
 * The signature of the function had been updated to return the index instead of the pointer. 
 *
 * If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.*
 *
 *******************************************************************************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // TODO: 细节有待提高,调了四五次,争取一次过
    int strStr(string haystack, string needle) {

      if (needle.size() == 0) return 0;
      if (haystack.size() < needle.size()) return -1;

      int left=0;
      int right=0;

      while (left<=haystack.size()-needle.size()) {

        right = 0;
        while (right<needle.size() && haystack[left+right] == needle[right]) {
          right++;
        }

        if (right==needle.size()) {
          break;
        }

        left++;

      }

      if (right == needle.size()) {
        return left;
      } else {
        return -1;
      }

    }
};

int main() {
  cout<<(new Solution)->strStr("a", "a")<<endl;
}
