// Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Author : Albin. Zeng
// Date   : 2015-04-10

/*****************************************************************************************
 *
 * Given a string, find the length of the longest substring without repeating characters. 
 * For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
 * which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 *
 *****************************************************************************************/
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      map<char, int> m;
      int max = 0;
      int last_repeat_pos = -1;
      for (int i=0; i<s.length(); i++) {
        char c = s[i];
        if (m.find(c) != m.end() && m[c]>last_repeat_pos) {
          last_repeat_pos = m[c];
        }
        m[c] = i;
        if (i-last_repeat_pos > max)
          max = i-last_repeat_pos;
      }
      return max;
    }

    // not use <map>
    int lengthOfLongestSubstring1(string s) {
      const int MAX_CHAR_SIZE = 256;
      int m[MAX_CHAR_SIZE] = {-1};
      for (int i=0; i<MAX_CHAR_SIZE; i++) {
        m[i] = -1;
      }
      int max = 0;
      int last_repeat_pos = -1;
      char c;
      for(int i=0; i<s.length(); i++) {
        c = s[i];
        if (m[c]>last_repeat_pos) {
          last_repeat_pos = m[c];
        }
        m[c] = i;
        if (i-last_repeat_pos>max) {
          max = i-last_repeat_pos;
        }
      }
      return max;
    }
};

int main(int argc, char* argv[]) {
  string str = "c";
  cout<<(new Solution)->lengthOfLongestSubstring1(str)<<endl;
  return 0;
}
